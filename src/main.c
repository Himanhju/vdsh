#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "color.h"
#include "shell/shell.h"
#include "run/run.h"
#include "file/file.h"

int main(int argc, char** argv){
    if(sh_init() != 0){
        return 1;
    }
    if(argc == 1){
        // if it is interactive
    }else if(argv[1][0] == '-'){
        
    }
    int args = 0;
    while (argv[args] != NULL) {
        args++;
    }
    execve(get_exe("ls"),argv, NULL);
    sh_clean();
    return 0;
}