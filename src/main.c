#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "globals.h"
#include "shell/shell.h"
#include "run/run.h"
#include "file/file.h"
char *PATH;

int main(void){
    if(sh_init() != 0){
        return 2;
    }
    if(PATH == NULL){
        fprintf(stderr, "PATH IS NULL");
        return 1;
    }
    printf("PATH=%s\n", PATH);
    return 0;
}