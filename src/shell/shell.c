#include <string.h>
#include <stdlib.h>
#include "shell.h"

char* varPATH;
char* varPWD;

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
    char initPATH[] = ":/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin";
    for(int i = 0; i < strlen(":/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin"); i++){
        varPATH[i] = initPATH[i];
    }
    char initPWD[] = "/home/himanhju/";
    for(int i = 0; i < strlen("/home/himanhju/"); i++){
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