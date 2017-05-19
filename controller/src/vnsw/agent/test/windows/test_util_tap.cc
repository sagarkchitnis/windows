/*
 * Copyright (c) 2014 Juniper Networks, Inc. All rights reserved.
 */


#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/socket.h>
#include <cstring>
#include <string>
#include<WinSock2.h> 
#include <net/if.h>
#include <unistd.h>


//WINDOWSFIX: needs windows implementation for the TAP interface


void DeleteTap(int fd) {
	assert(0);
}

void DeleteTapIntf(const int fd[], int count) {
    for (int i = 0; i < count; i++) {
        DeleteTap(fd[i]);
    }
}

int CreateTap(const char *name) {
    int fd;
	assert(0);
    return fd;
}

void CreateTapIntf(const char *name, int count) {
    char ifname[IF_NAMESIZE];

    for (int i = 0; i < count; i++) {
        snprintf(ifname, IF_NAMESIZE, "%s%d", name, i);
        CreateTap(ifname);
    }
}

void CreateTapInterfaces(const char *name, int count, int *fd) {
	assert(0);
}

