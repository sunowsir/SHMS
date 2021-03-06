/*
* File Name: needHead.h
* Author:    sunowsir
* Mail:      sunowsir@protonmail.com
* GitHub:    github.com/sunowsir
* Created Time: 2018年11月13日 星期二 20时04分02秒
*/

#ifndef _NEEDHEAD_H
#define _NEEDHEAD_H

#include <time.h>
#include <math.h>
#include <wait.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXBUFF 4096

#define CPU_INFO 100
#define DISK_INFO 101
#define MALIPS_INFO 102
#define MEM_INFO 103
#define SYS_INFO 104
#define USER_INFO 105
#define DATANULL 106
#define CLOSE_NOW 107

#define CPU_WARN 200
#define DISK_WARN 201
#define MALIPS_WARN 202
#define MEM_WARN 203
#define SYS_WARN 204
#define USER_WARN 205

/* 配置文件路径 */

#define CONF_SERVER "/etc/SHMS-server/server.conf"
#define CONF_MASTER "/etc/SHMS-master/master.conf"

/* 程序运行日志路径 */
#define RUN_LOG_SERVER "/var/log/SHMS-server/SHMS-Server.log"
#define RUN_LOG_MASTER "/var/log/SHMS-master/SHMS-Master.log"

/* 每次最大发送长度 */

#define TRANS_MAX 1024

#endif
