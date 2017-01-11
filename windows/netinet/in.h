/* Copyright (C) 1991-2001, 2003, 2004, 2006 Free Software Foundation, Inc.
This file is part of the GNU C Library.

The GNU C Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

The GNU C Library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with the GNU C Library; if not, write to the Free
Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
02111-1307 USA.  */


#pragma once

#include<sys/wintypes.h>
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef	uint32_t		in_addr_t;
/*struct linux_sockaddr {
	unsigned short    sa_family;    // address family, AF_xxx
	char              sa_data[14];  // 14 bytes of protocol address
};


// IPv4 AF_INET sockets:

struct linux_sockaddr_in {
	short            sin_family;   // e.g. AF_INET, AF_INET6
	unsigned short   sin_port;     // e.g. htons(3490)
	struct in_addr   sin_addr;     // see struct in_addr, below
	char             sin_zero[8];  // zero this if you want to
};

struct linux_in_addr {
	unsigned long s_addr;          // load with inet_pton()
};
*/