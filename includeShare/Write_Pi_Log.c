/*************************************************************************
	> File Name:    Write_Pi_Log.c
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月30日 星期日 16时36分33秒
 ************************************************************************/

#include "./Write_Pi_Log.h"

int Write_Pi_Log(char *PiHealthLog, const char *format, ...) {
    va_list arg;
    int para_num = 0;
    va_start(arg, format);

    FILE *fp = fopen(PiHealthLog, "a");

    if (fp == NULL)  {
        perror("Write_Pi_Log.c->Write_Pi_Log:(15)fopen");
        exit(1);
    }

    for (int i = 0; format[i]; i++) {
        if (format[i] == '%' && format[i + 1] == 's') {
            char *para = va_arg(arg, char *);
            fprintf(fp, "%s", para);
        } else {
            fputc(format[i], fp);
        }
    }

    fclose(fp);
}
