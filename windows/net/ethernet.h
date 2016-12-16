
#pragma once
#include "sys/types.h"

#define PACK( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop) )

#define ETH_ALEN   6

PACK(
struct ether_addr
{
	u_int8_t ether_addr_octet[ETH_ALEN];
} ) ;