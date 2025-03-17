#include <string.h>

#include "../globals.h"
#include "shell.h"


void sh_init(void){
    //ONLY TO BE USED FOR INITIALIZATION OF THE PATH, PWD AND OTHER GLOBAL VARIABLES
    char initPATH[] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin";
    for(int i = 0; i < strlen("/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin"); i++){
        PATH[i] = initPATH[i];
    }
    char initPWD[] = "/home/himanhju/";
    for(int i = 0; i < strlen("/home/himanhju/"); i++){
        PWD[i] = initPWD[i];
    }
    if((strcmp(initPATH, PATH) == 0) && (strcmp(initPWD, PWD) == 0)){ // if they both copied successfully
        return 0;
    }else{
        if ((strcmp(initPATH, PATH) + strcmp(initPWD, PWD)) == 0){
            return -1;
        }
        return(strcmp(initPATH, PATH) + strcmp(initPWD, PWD));
    }
}