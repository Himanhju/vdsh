#include <stdio.h>

#include "color.h"
#include "globals.h"
#include "run/run.h"
#include "file/file.h"


int main(void){
    char* PATH = get_var("PATH");
    if(PATH == NULL){
        fprintf(stderr, "PATH IS NULL");
        return 1;
    }
    printf("PATH=%s\n", PATH);
    free(PATH);
    return 0;
}