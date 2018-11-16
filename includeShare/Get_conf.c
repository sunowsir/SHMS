/*************************************************************************
	> File Name:    Get_conf.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月30日 星期日 10时26分19秒
 ************************************************************************/

#include "Get_conf.h"

char *getConf(const char *needVar, char *confPath) {
    FILE *fp = fopen(confPath, "r");

    if (fp == NULL) {
        perror("Get_conf.c : Get_conf->(12) 'fopen' ");
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

    fclose(fp);

    return (!strcmp(varValue, "") ? NULL : varValue);
}

int main(int argc, char **argv) {
    char path[] = "/home/sunowsir/1.Learning/4.project/2.Socket/test.conf";
    char *var = argv[1];
    char *ret = getConf(var, path);
    printf("%s", ret);
    free(ret);
    return 0;
}
