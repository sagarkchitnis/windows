

#include "winutils.h"
#include "TlHelp32.h"

#include "net/ethernet.h"
#include <intrin.h> 

DWORD getppid()
{
	HANDLE hSnapshot = INVALID_HANDLE_VALUE;
	PROCESSENTRY32 pe32;
	DWORD ppid = 0, pid = GetCurrentProcessId();

	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	__try {
		if (hSnapshot == INVALID_HANDLE_VALUE) __leave;

		ZeroMemory(&pe32, sizeof(pe32));
		pe32.dwSize = sizeof(pe32);
		if (!Process32First(hSnapshot, &pe32)) __leave;

		do {
			if (pe32.th32ProcessID == pid) {
				ppid = pe32.th32ParentProcessID;
				break;
			}
		} while (Process32Next(hSnapshot, &pe32));

	}

	__finally {
		if (hSnapshot != INVALID_HANDLE_VALUE) CloseHandle(hSnapshot);
	}
	return ppid;
}


void bzero(void *to, int count)
{
	unsigned char *chto = static_cast<unsigned char*>(to);
	while (count-- > 0)
	{
		*chto++ = 0;
	}
}


u_int32_t custom_htonl(u_int32_t x)
{
	//#if BYTE_ORDER == LITTLE_ENDIAN
	u_char *s = (u_char *)&x;
	return (u_int32_t)(s[0] << 24 | s[1] << 16 | s[2] << 8 | s[3]);
	//else
	//	return x;
	//#endif
}
unsigned int  sleep(unsigned int sec) { Sleep(1000 * sec); return 0; }
//void  bzero(unsigned char *, int) { }
int  usleep(unsigned int x) { Sleep(x);  return 0; }
int  getrlimit(int, struct rlimit *) { return 0; }
int  getrusage(int, struct rusage *) { return 0; }
int  close(int) { return 0; }
int  setrlimit(int, struct rlimit const *) { return 0; }
void  WindowsCloseTaskFiles(void) {}
char * gettempdirectory(void) 
{ 
	DWORD WINAPI GetTempPath(
		_In_  DWORD  nBufferLength,
		_Out_ LPTSTR lpBuffer
	);
	
	return 0; 

}
//unsigned long  getppid(void) { return 0; }

int ioctl(int fd, unsigned long request, ...) { return 0; }
unsigned int  if_nametoindex(char const *) { return 0; }
void  if_freenameindex(struct if_nameindex *) { return; }
struct if_nameindex *  if_nameindex(void) { return 0; }
char *windows_if_indextoname(unsigned int ifindex, char *ifname) { return nullptr; }
static inline int
xdigit(char c) {
	unsigned d;
	d = (unsigned)(c - '0');
	if (d < 10) return (int)d;
	d = (unsigned)(c - 'a');
	if (d < 6) return (int)(10 + d);
	d = (unsigned)(c - 'A');
	if (d < 6) return (int)(10 + d);
	return -1;
}

struct ether_addr *
	ether_aton_r(const char *asc, struct ether_addr * addr)
{
	int i, val0, val1;
	for (i = 0; i < ETHER_ADDR_LEN; ++i) {
		val0 = xdigit(*asc);
		asc++;
		if (val0 < 0)
			return NULL;

		val1 = xdigit(*asc);
		asc++;
		if (val1 < 0)
			return NULL;

		addr->ether_addr_octet[i] = (u_int8_t)((val0 << 4) + val1);

		if (i < ETHER_ADDR_LEN - 1) {
			if (*asc != ':')
				return NULL;
			asc++;
		}
	}
	if (*asc != '\0')
		return NULL;
	return addr;
}

struct ether_addr *
	ether_aton(const char *asc)
{
	static struct ether_addr addr;
	return ether_aton_r(asc, &addr);
}

//similar functionality as ffsl in linux - called in bitset.cc
int find_first_set64(uint64_t value) 
{
	unsigned long index = 0;
	unsigned char isNonZero= _BitScanForward64(&index, value);
	if (isNonZero)	{

		return index + 1;
		//ffsl assumes least significant bit is position is 1.
		//_bitScanForward assumes least significant bt position is 0.
	}
	else return 0;
}