#pragma once
#define _WINSOCKAPI_    // stops windows.h including winsock.h
#include<windows.h>
#include <stdlib.h>

int getloadavg(double loadavg[], int nelem);;

#define CLOCK_REALTIME                  0
#define CLOCK_MONOTONIC                 1
typedef  unsigned int   useconds_t;
typedef unsigned int            uint;
typedef unsigned long           ulong;
typedef SSIZE_T              ssize_t;
/*struct timeval {
	time_t          tv_sec;
	suseconds_t     tv_usec;
};

struct timespec {
	time_t          tv_sec;
	long            tv_nsec;
};*/

char *ctime_r(time_t *, char[]);

int clock_gettime(int X, struct timespec *tv);
int usleep(useconds_t usec);
unsigned int sleep(unsigned int seconds);

char *gettempdirectory();
DWORD getppid();
void WindowsCloseTaskFiles();
#define PACK( ___somestructure___ ) __pragma( pack(push, 1) ) ___somestructure___ __pragma( pack(pop) )

#define strtok_r strtok_s


#define ETHER_ADDR_LEN 6
#define	ETHERTYPE_IP	0x0800		
/* IP protocol */
/*
  2  * Ethernet netdevice using ATM AAL5 as underlying carrier
  3  * (RFC1483 obsoleted by RFC2684) for Linux
  4  *
  5  * Authors: Marcell GAL, 2000, XDSL Ltd, Hungary
  6  *          Eric Kinzie, 2006-2007, US Naval Research Laboratory
  7  */

#define ETHERTYPE_IPV4  0x0800
#define ETHERTYPE_IPV6  0x86dd

void bzero(unsigned char *to, int count);
typedef unsigned long   __kernel_ulong_t;
struct rlimit {
	         __kernel_ulong_t        rlim_cur;
	         __kernel_ulong_t        rlim_max;
};
#ifndef RLIMIT_NOFILE
# define RLIMIT_NOFILE          7       /* max number of open files */
#endif

int getrlimit(int resource, struct rlimit *rlp);

int setrlimit(int resource, const struct rlimit *rlp);

#define strncasecmp _strnicmp
#define strcasecmp _stricmp
