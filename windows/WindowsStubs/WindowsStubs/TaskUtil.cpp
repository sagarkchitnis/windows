#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include<string>
#include <cctype>
#include <algorithm>
#include <process.h>
#include <memory>

/*
std::string WindowsTaskExecute(std::string execpath, bool usePipes, bool bWait)
{
	
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	SECURITY_ATTRIBUTES securityAttr;
	HANDLE inputPipe, outputPipe;
	std::string  output;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	ZeroMemory(&securityAttr, sizeof(securityAttr));
	securityAttr.nLength = sizeof(securityAttr);
	securityAttr.bInheritHandle = TRUE;





	int len;
	int slength = (int)execpath.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, execpath.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, execpath.c_str(), slength, buf, len);
	//std::wstring r(buf);
	//delete[] buf;
	//return r;
	

	if (usePipes)
	{


		::CreatePipe(&inputPipe, &outputPipe, &securityAttr, 0);

		si.dwFlags = STARTF_USESTDHANDLES;
		si.hStdInput = NULL;
		si.hStdOutput = outputPipe;
		si.hStdError = outputPipe;
	}

	if (!CreateProcess(NULL,   // No module name (use command line)
		buf,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		TRUE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		delete[] buf;
		DWORD le = GetLastError();
		std::cout << "CreateProcess Failed. Error code:" << le << std::endl;
		
		return "-1";
	}

	if(usePipes || bWait)
	   WaitForSingleObject(pi.hProcess, INFINITE);

	if (usePipes)
	{

		CloseHandle(outputPipe);

		const int BUFFER_SIZE = 200;
		DWORD NumberOfBytesRead = 0;
		do
		{
			char buf[BUFFER_SIZE+1] = "";
		
			if (::ReadFile(inputPipe, buf, BUFFER_SIZE, &NumberOfBytesRead, 0))
			{
				if (NumberOfBytesRead == 0)
					break;

				buf[NumberOfBytesRead] = '\0';

				output += std::string(buf);
			}

		} while (NumberOfBytesRead != 0);

		CloseHandle(inputPipe);

	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	delete[] buf;
	output.erase(std::remove_if(output.begin(), output.end(), [](char c) { return std::isspace(c); }), output.end());
	return output;
}
*/




int osspecific_getpid(void)
{
    return _getpid();
}


FILE *popen(const char *command, const char *type)
{
    return _popen(command, type);
}

int pclose(FILE *stream)
{
    return _pclose(stream);
}


struct ProcessInfoDeleter {
    void operator()(PROCESS_INFORMATION* ppi) {
        if (ppi)
        {
            if (ppi->hProcess)
                CloseHandle(ppi->hProcess);
            if (ppi->hThread)
                CloseHandle(ppi->hThread);
            delete ppi;
        }
    }
};

bool WindowsTaskExecute(std::string execpath, std::string *pOutput, bool bWait) {
    STARTUPINFO si;
    SECURITY_ATTRIBUTES securityAttr;
    HANDLE inputPipe, outputPipe;
    bool retval = true;
    std::unique_ptr< PROCESS_INFORMATION, ProcessInfoDeleter > upi(new PROCESS_INFORMATION);
    PROCESS_INFORMATION *ppi = upi.get();//only for clarity purposes, ownership is not relinquished
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(ppi, sizeof(PROCESS_INFORMATION));
    ZeroMemory(&securityAttr, sizeof(securityAttr));
    securityAttr.nLength = sizeof(securityAttr);
    securityAttr.bInheritHandle = TRUE;
    int len;
    int slength = (int)execpath.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, execpath.c_str(), slength, 0, 0);
    auto ubuf = std::unique_ptr< wchar_t[]>{ new wchar_t[len] };
    wchar_t *pbuf = ubuf.get(); //only for clarity
    MultiByteToWideChar(CP_ACP, 0, execpath.c_str(), slength, pbuf, len);
    if (pOutput) {
        CreatePipe(&inputPipe, &outputPipe, &securityAttr, 0);
        si.dwFlags = STARTF_USESTDHANDLES;
        si.hStdInput = NULL;
        si.hStdOutput = outputPipe;
        si.hStdError = outputPipe;
    }

    if (!CreateProcess(NULL, pbuf, NULL, NULL, TRUE, 0, NULL, NULL, &si, ppi)) {
        DWORD le = GetLastError();
        std::cout << "CreateProcess Failed. Error code:" << le << std::endl;
        retval = false;
    }

    if(pOutput || bWait )
    if (retval && (WaitForSingleObject(ppi->hProcess, INFINITE) == WAIT_FAILED) ) {
        DWORD le = GetLastError();
        std::cout << "WaitForSingleObject Failed. Error code:" << le << std::endl;
        retval = false;
    }

    if (retval && pOutput) {
        CloseHandle(outputPipe);
        const int BUFFER_SIZE = 200;
        DWORD nNumberOfBytesToRead = 0;
        do {
            char localbuf[BUFFER_SIZE + 1];

            if (::ReadFile(inputPipe, localbuf, BUFFER_SIZE, &nNumberOfBytesToRead, 0)) {
                if (nNumberOfBytesToRead == 0)
                    break;

                localbuf[nNumberOfBytesToRead] = '\0';

                *pOutput += localbuf;
            }

        } while (nNumberOfBytesToRead != 0);
        CloseHandle(inputPipe);
    }

    return retval;
}

/*
int system(const char * command)
{
    if (command == nullptr) return 0;
    bool bRet = WindowsTaskExecute(command, nullptr, true);
    return 0;//fix this //WINDOWS-TEMP
}

*/

