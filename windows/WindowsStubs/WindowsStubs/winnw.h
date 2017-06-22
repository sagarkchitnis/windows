#pragma once
#include "net/ethernet.h"
#include <intrin.h> 
#include <Iphlpapi.h>
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
