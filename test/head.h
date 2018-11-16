/*************************************************************************
	> File Name:    head.h
	> Author:       sunowsir
	> Mail:         sunowsir@protonmail.com
	> Created Time: 2018年09月24日 星期一 09时20分14秒
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H

// include file.
#include <wait.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Create connect.
void Cret_cont(int *, char *, int);

// close connect.
void Sclose(int *);

// Send Word.
void Sendw(int *, char *);

// Send from stdio
void Sendio(int *);

// Send from file
void Sendfile(int *, char *);

// Get file size.
int Get_filesize(char *);

// Resolve configuraton files.
int Get_conf(char *, char *);

#endif

