#pragma once
#include <string>
std::string WindowsTaskExecute(std::string execpath, bool usePipes=false, bool bWait=true);
int osspecific_getpid(void);
FILE *popen(const char *command, const char *type);
int pclose(FILE *stream);

