
#pragma once
typedef long long time_t;
typedef long long suseconds_t;

struct linux_timeval {
	        time_t          tv_sec;         /* seconds */
	        suseconds_t     tv_usec;        /* microseconds */
};
