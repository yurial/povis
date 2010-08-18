void ProcessMinPrior()
{
HANDLE hProcessSnap=INVALID_HANDLE_VALUE;
PROCESSENTRY32 pe32;
hProcessSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
if(hProcessSnap==INVALID_HANDLE_VALUE ) return;
pe32.dwSize=sizeof(PROCESSENTRY32);
if(!Process32First(hProcessSnap,&pe32))
  {
  CloseHandle(hProcessSnap);
  return;
  }
do
{
HANDLE hProcess=OpenProcess(PROCESS_SET_INFORMATION,FALSE,pe32.th32ProcessID);
if (hProcess)  
  {
  SetPriorityClass(hProcess,IDLE_PRIORITY_CLASS);
  SetProcessPriorityBoost(hProcess,TRUE);
  }
CloseHandle(hProcess);
}
while(Process32Next(hProcessSnap,&pe32));
CloseHandle(hProcessSnap);
}