/*
 * Copyright (c) 2014 Juniper Networks, Inc. All rights reserved.
 */
 
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>

#include "base/logging.h"
#include "cmn/agent_cmn.h"
#include "init/agent_param.h"
#include "sandesh/sandesh_types.h"
#include "sandesh/sandesh.h"
#include "sandesh/sandesh_trace.h"
#include "pkt/pkt_types.h"
#include "pkt/pkt_init.h"
#include "../pkt0_interface.h"

#define TUN_INTF_CLONE_DEV "/dev/net/tun"

#define TAP_TRACE(obj, ...)                                              \
do {                                                                     \
    Tap##obj::TraceMsg(PacketTraceBuf, __FILE__, __LINE__, __VA_ARGS__); \
} while (false)                                                          \

///////////////////////////////////////////////////////////////////////////////


void Pkt0Interface::InitControlInterface() {
  

    

    
}

void Pkt0RawInterface::InitControlInterface() {
   


}
