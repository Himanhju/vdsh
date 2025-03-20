#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include "misc.h"

char** returns;

int numstrs;

struct stat file_GetStats(const char *filename) {
  struct stat file_stats;

  
  if (stat(filename, &file_stats) < 0) {
    file_stats.st_size = -1;
    return file_stats;
  }

  return file_stats;
}
/*
char** splice(char* string ,char cha){
    char str[strlen(string) + 1];
    str[0] = cha;
    for(int i = 1; i < strlen(string) + 1; i++){
        str[i] = string[i-1];
    }
    int str_len = strlen(str);
    numstrs = 0;
    for(int c = 0; c < str_len; c++) {
       if(str[c] == cha){
           numstrs++;
       }
    }
    numstrs++;
    int strlens[numstrs];
    int strstarts[numstrs];
    int curstrs = -1;
    for(int o = 0; o < numstrs; o++){
       strlens[o] = 0;
       strstarts[o] = 0;
    }
    for(int c = 0; c < str_len; c++){
       if(str[c] == cha){ curstrs++; strstarts[curstrs] = c + 1; continue;}                                             
       strlens[curstrs]++;
    }
    char curstr[str_len];
    returns = calloc(numstrs, sizeof(char*));
    for(int i = 0; i < numstrs; i++){
        for(int o = 0; o < 4096; o++) {
            curstr[o] = '\0';
        }
        for(int c = strstarts[i]; c < strstarts[i] + strlens[i]; c++) {
            curstr[c - strstarts[i]] = str[c];
        }
        returns[i] = calloc(strlen(curstr),sizeof(char));
        strcpy(returns[i],curstr);
    }
    return returns;
}

void splice_clean(void){
    for(int i = 0; i < numstrs; i++){
        free(returns[i]);
    }
    free(returns);
}
*/
int sqlen(char** sqr){
    int args = 0;
    while (sqr[args] != NULL) {
        args++;
    }
    return args;
}