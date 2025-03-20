#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>

#include "../color.h"
#include "shell.h"

char* varPATH;
char* varPWD;

char** PArray;
int numparam;

int sh_init(void){
    //ONLY TO BE USED FOR INITIALIZATION OF THE PATH, PWD AND OTHER GLOBAL VARIABLES
    varPATH = calloc(4096, sizeof(char));
    if(varPATH == NULL){
        return 1;
    }
    varPWD = calloc(4096, sizeof(char));
    if(varPWD == NULL){
        return 2;
    }
    char initPATH[4096] = ":/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin";
    for(int i = 0; i < strlen(":/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin"); i++){
        varPATH[i] = initPATH[i];
    }
    char* User = getlogin();
    char initPWD[4096] = "/home/";
    if(strncmp("root",User,4) == 0){
        for(int i = 0; i < 6; i++){
            initPWD[i] = '\0';
        }
        strcpy(initPWD, "/root");       //error in this function
    }else{
        strcat(initPWD, User);
    }
    for(int i = 0; i < strlen(initPWD); i++){
        varPWD[i] = initPWD[i];
    }
    if((strcmp(initPATH, varPATH) == 0) && (strcmp(initPWD, varPWD) == 0)){ // if they both copied successfully
        return 0;
    }else{
        if ((strcmp(initPATH, varPATH) + strcmp(initPWD, varPWD)) == 0){
            return -1;
        }
        return(strcmp(initPATH, varPATH) + strcmp(initPWD, varPWD));
    }
}

void sh_clean(void){
    free(varPATH); //free doesnt fail unless it has already been freed
    free(varPWD);
}

char* get_PATH(void){
    return varPATH;
}
char* get_PWD(void){
    return varPWD;
}

void splice(char* string ,char cha){
    char str[strlen(string) + 1];
    str[0] = cha;
    for(int i = 1; i < strlen(string) + 1; i++){
        str[i] = string[i-1];
    }
    int str_len = strlen(str);
    numparam = 0;
    for(int c = 0; c < str_len; c++) {
       if(str[c] == cha){
           numparam++;
       }
    }
    numparam++;
    int strlens[numparam];
    int strstarts[numparam];
    int curstrs = -1;
    for(int o = 0; o < numparam; o++){
       strlens[o] = 0;
       strstarts[o] = 0;
    }
    for(int c = 0; c < str_len; c++){
       if(str[c] == cha){ curstrs++; strstarts[curstrs] = c + 1; continue;}                                             
       strlens[curstrs]++;
    }
    char curstr[str_len];
    //PArray[numparam][1024];
    PArray = calloc(numparam, sizeof(char*));
    for(int i = 0; i < numparam; i++){
        for(int o = 0; o < 4096; o++) {
            curstr[o] = '\0';
        }
        for(int c = strstarts[i]; c < strstarts[i] + strlens[i]; c++) {
            curstr[c - strstarts[i]] = str[c];
        }
        PArray[i] = calloc(1024, sizeof(char));
        strcpy(PArray[i],curstr);
    }
}
int IShell(){
    char cmd[4096];
    char* User = getlogin();
    char Hostname[256];
    int exit = 0;
    while(exit != 1){
        if(gethostname(Hostname, sizeof(Hostname)) != 0){
        return 1;
        }
        printf(BD_GREEN"%s@%s"RESET":"BD_BLUE"%s"RESET,User, Hostname, get_PWD());
        if(strncmp(User,"root",4)){
            printf("# ");
        }else{
        printf("$ ");
        }
        scanf("%s", cmd);
        if(strncmp(cmd, "exit", 4) == 0){
            exit = 1;
        }
        splice(cmd, ' ');
        char arga[numparam][1024];
        char args[numparam - 1][1024];
        for(int i = 0; i < numparam; i++){
            strcpy(arga[i],PArray[i]); 
        }

        for(int i = 0; i < numparam; i++){
            free(PArray[i]);
        }
        free(PArray);
        char* exe = get_exe(arga[0]);
        for(int i = 1; i < numparam; i++){
            strcpy(args[i-1], arga[i]);
        }
        execve(exe, args, NULL);
    }
    return 0;
}

char* get_exe(char* command){
    char* PATH = get_PATH();
    int PATH_len = strlen(PATH);
    int numPATH = 0;
    for(int c = 0; c < PATH_len; c++) {
        if(PATH[c] == ':'){
            numPATH++;
        }
    }                        //can get full paths in this "for" loop (can also get in next for loop)
    numPATH++;
    int PATHlens[numPATH];
    int PATHstarts[numPATH];
    int curPATH = -1;
    for(int o = 0; o < numPATH; o++){
        PATHlens[o] = 0;
        PATHstarts[o] = 0;
    }
    for(int c = 0; c < PATH_len; c++){
        if(PATH[c] == ':'){ curPATH++; PATHstarts[curPATH] = c + 1; continue;}                                             
        PATHlens[curPATH]++;
    }
    DIR *dir;
    struct dirent *entry;
    char* file;
    char curdir[4096]; //4096 is usually the kernel set pathlength
    for(int i = 0; i < numPATH; i++){
        for(int o = 0; o < 4096; o++) {
            curdir[o] = '\0';
        }
        for(int c = PATHstarts[i]; c < PATHstarts[i] + PATHlens[i]; c++) {
            curdir[c - PATHstarts[i]] = PATH[c];
        }

        dir = opendir(curdir);
        if (dir == NULL) {
            fprintf(stderr,"Error reading directory: %s\n", curdir);
            return NULL;
        }
        while ((entry = readdir(dir)) != NULL) {
            if(strcmp(entry->d_name,command) == 0){
                //file found
                file = strcat(curdir,"/");
                file = strcat(file, entry->d_name);
                return file;
            }
        }
        closedir(dir);
    }
    return "cnf";
}