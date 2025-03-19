#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "../global/global.h"
#include "run.h"

char* get_exe(char* command){
    
    int PATH_len = strlen(PATH);
    int numPATH = 0;
    for(int c = 0; c < PATH_len; c++) {if(PATH[c] == ':'){ numPATH++;}}                        //can get full paths in this "for" loop (can also get in next for loop)
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
        for(int o = 0; 0 < 4096; o++) {curdir[o] = '\0';}
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
    fprintf(stderr, "vdsh: %s: Command Not Found\n", command);
    return "cnf";
}

/*

#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }                                                               example for directory reading
    
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    
    closedir(dir);
    return 0;
}
    
*/