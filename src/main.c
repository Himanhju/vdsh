#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#include "shell/shell.h"
#include "misc/misc.h"

int main(int argc, char** argv){
    if(sh_init() != 0){
        return 1;
    }
    if(argc == 1){
        IShell();
    }else if(strncmp(argv[1], "-c", 2)){ // if it has vdsh -c "command to run"
        /*
        char** spliced = splice(argv[2], ' ');
        for(int i = 0; i < sqlen(spliced); i++){
            printf("%s ", spliced[i]);
        }
        */
    }
    
    //execve(get_exe("ls"),argv, NULL);
    sh_clean();
    return 0;
}