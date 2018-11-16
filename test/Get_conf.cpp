/*************************************************************************
	> File Name:    Get_conf.cpp
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月30日 星期日 10时26分19秒
 ************************************************************************/

#include "head.h"

int Get_conf(char *path_var, char *conf_path) {

    FILE *fp = fopen(conf_path, "r");

    if (fp == NULL) {
        perror("Get_conf.cpp:Get_conf->(12)fopen");
        exit(1);
    }

    char line[1024] = "";
    char need_var[1024] = "";

    strcpy(need_var, path_var);
    memset(path_var, 0, sizeof(path_var));

    while (fgets(line, 1024, fp) != NULL) {
       
        //Skip annotations.
        if (line[0] == '#') {
            continue;
        }

        // Determine whether the variable needed is in the configuration file.
        if (strstr(line, need_var) == NULL) {
            continue;
        }

        // Determine whether the variable name is the variable required.
        if (strcmp(strtok(line, "="), need_var)) {
            continue;
        }

        // Cut value of the variable needed.
        strcpy(path_var, strtok(NULL, "="));
    }

    fclose(fp);

    if (path_var == NULL) {
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    char path[] = "/home/sunowsir/Learning/C_language/Socket/test.conf";

    char *var = argv[1];

    Get_conf(var, path);

    printf("%s", var);

    return 0;
}
