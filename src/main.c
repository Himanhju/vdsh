#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"
#include "shell/shell.h"
#include "run/run.h"
#include "misc/misc.h"

int main(int argc, char** argv){
    if(sh_init() != 0){
        return 1;
    }
    if(argc == 1){
        // if it is interactive
    }else if(argv[1][0] == '-' && argv[1][1] == 'c'){
        char command[strlen(argv[2])];
        strcpy(command,argv[2]);
        
    }
    
    //execve(get_exe("ls"),argv, NULL);
    sh_clean();
    return 0;
}