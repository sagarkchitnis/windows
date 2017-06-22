#pragma once
#include <string>
bool WindowsTaskExecute(std::string execpath, std::string *pOutput = nullptr, bool bWait = true);
int osspecific_getpid(void);
FILE *popen(const char *command, const char *type);
int pclose(FILE *stream);
int CountProcessThreads(DWORD dwOwnerPID);

