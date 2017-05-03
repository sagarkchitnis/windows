// WindowsStubsTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "winutils.h"
#include "wmi.h"
#include "cpuinfo.h"
#include "taskutil.h"

#include<time.h>

int main()
{
	timespec ts;

	//clock_getres(CLOCK_MONOTONIC, &ts);
	//clock_gettime(CLOCK_MONOTONIC, &ts);
	//GetprocessPerformance();

//	TaskExecuteAndWait("c:\\python27\\python.exe");
	std::string str = TaskExecuteAndWait("where python", true);
	TaskExecuteAndWait(str, false);
    return 0;
}

