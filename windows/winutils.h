#pragma once
#include<windows.h>
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

typedef struct ether_header {
	     u_char  ether_dhost[6];
	     u_char  ether_shost[6];
	     u_short ether_type;
	
} ETHERHDR;


#define ETHER_ADDR_LEN 6
#define	ETHERTYPE_IP	0x0800		/* IP protocol */

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