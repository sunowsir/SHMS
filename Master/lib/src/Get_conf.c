/*************************************************************************
	> File Name:    Get_conf.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月30日 星期日 10时26分19秒
 ************************************************************************/

#include "../include/Get_conf.h"

char *getConf(const char *needVar, const char *confPath) {
    FILE *fp = fopen(confPath, "r");

    if (fp == NULL) {
        printf("confPath:(%s)\n", confPath);
        perror("Get_conf.c (Get_conf->(12) 'fopen') ");
        return NULL;
    }

    char line[1024] = "";
    char *varValue = (char *)calloc(sizeof(char), MAXBUFF);
    
    while (fgets(line, MAXBUFF, fp) != NULL) {
       
        //Skip annotations.
        if (line[0] == '#') {
            continue;
        }
        
        // Determine whether the variable needed is in the configuration file.
        if (strstr(line, needVar) == NULL) {
            continue;
        }
        
        /* Determine whether the variable name is the variable required. */

        if (!strcmp(strtok(line, "="), needVar)) {
            
            /* Cut value of the variable needed. */
            
            strcpy(varValue, strtok(NULL, "="));
        }
    }
    
    if (varValue[(int)strlen(varValue) - 1] == ' ' || varValue[(int)strlen(varValue) - 1] == '\n' ) {
        varValue[(int)strlen(varValue) - 1] = '\0';
    }
    
    fclose(fp);
    char *retStr=strdup(varValue);
    free(varValue);

    return (!strcmp(retStr, "") ? NULL : retStr);
}



