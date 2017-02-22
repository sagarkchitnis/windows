# -*- mode: python; -*-

#
# Copyright (c) 2013 Juniper Networks, Inc. All rights reserved.
#

# repository root directory
import os
import sys
sys.path.append('tools/build')

import rules
conf = Configure(DefaultEnvironment(ENV = os.environ, TARGET_ARCH='x86'))
#conf = Configure(DefaultEnvironment(ENV = os.environ, TARGET_ARCH='amd64_x86'))
#conf = Configure(DefaultEnvironment(ENV = os.environ,MSVC_USE_SCRIPT = "c:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\bin\\amd64_x86\\vcvarsamd64_x86.bat"))
#conf = Configure(DefaultEnvironment(ENV = os.environ,MSVC_USE_SCRIPT = "vcvarsamd64_x86.bat"))
env = rules.SetupBuildEnvironment(conf)

SConscript(dirs=['controller',  'vrouter', 'tools/sandesh'])


