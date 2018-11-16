/*
* File Name: getAllIP.c
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月15日 星期四 20时42分16秒
*/

#include "./getAllIP.h"
    
int getAllIP(LinkList **list, int num) {
    char *s1, *s2, *s3, *s4, *e1, *e2, *e3, *e4, path[] = {"./master.conf"};
    int start1, start2, start3, start4;
    int end1, end2, end3, end4;
    
    s1 = getConf("start1", path);
    s2 = getConf("start2", path);
    s3 = getConf("start3", path);
    s4 = getConf("start4", path);
    e1 = getConf("end1", path);
    e1 = getConf("end1", path);
    e1 = getConf("end1", path);
    e1 = getConf("end1", path);
    
    if (!s1 || !s2 || !s3 || !s4 || !e1 || !e2 || !e3 || !e4) {
        printf("\033[1;31merror\033[0m : master.conf error : Network segment configuration error!\n");
    }
    
    start1 = StrtoInt(s1);
    start2 = StrtoInt(s2);
    start3 = StrtoInt(s3);
    start4 = StrtoInt(s4);
    end1 = StrtoInt(e1);
    end2 = StrtoInt(e2);
    end3 = StrtoInt(e3);
    end4 = StrtoInt(e4);
    
    // ILE *fp = fopen("./client.info", "w");
    
    int listNum = 0;

    for (int i = start1; i <= end1; i++) {
        for (int j = start2; j <= end2; j++) {
            for (int k = start3; k <= end3; k++) {
                for (int x = start4; x <= end4; x++) {
                    sprintf(list[listNum], "%d.%d.%d.%d\n", i, j, k, x);
                }
            }
        }
    }
    
    free(s1);
    free(s2);
    free(s3);
    free(s4);
    free(e1);
    free(e2);
    free(e3);
    free(e4);
    // fclose(fp);

    return 0;
}

