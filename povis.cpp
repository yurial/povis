#include <windows.h>

void main()
{
__int64 a=0;
SetThreadPriority(GetCurrentThread(),THREAD_PRIORITY_TIME_CRITICAL);
SetPriorityClass(GetCurrentProcess(),REALTIME_PRIORITY_CLASS);
while (TRUE) a++;
}