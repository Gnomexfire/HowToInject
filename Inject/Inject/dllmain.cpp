#include <Windows.h>
#include <iostream>
extern int ShowMainWindow();
using namespace std;

void WINAPI StarThread(){
	ShowMainWindow();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		// Inject
		DisableThreadLibraryCalls(hModule);
		AllocConsole();
		if (CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)StarThread, NULL, 0, NULL) == NULL){
			
			
			return FALSE;
		}
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


