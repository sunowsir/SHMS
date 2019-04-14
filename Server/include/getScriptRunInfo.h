/*
 * File Name:    getScriptRunInfo.h
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2018年11月25日 星期日 16时35分32秒
 */

#ifndef _GETSCRIPTRUNINFO_H
#define _GETSCRIPTRUNINFO_H

#include "needHead.h"
#include "Get_conf.h"

/* The space pointed to by the character pointer returned by this function needs to call ‘free’ release. If the fetch fails, it returns ‘NULL’.  */

/* return : success(data string), false(NULL) */

char *getScriptRunInfo(int /* Signifier */);

#endif
