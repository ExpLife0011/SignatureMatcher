#include <xlib.h>

#include "SignatureMatcher.h"

DWORD WINAPI StartCLR(PVOID lParam);

//! ʹ��ȫ�ֱ�����ʼ��CLR���ڱ���x64 DLL��ϱ�̵ĳ�ʼ������
static HANDLE hThd = CreateThread(nullptr, 0, StartCLR, nullptr, 0, nullptr);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
  {
  UNREFERENCED_PARAMETER(hModule);
  UNREFERENCED_PARAMETER(lpReserved);
  switch(ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
      break;
    case DLL_THREAD_ATTACH:
      break;
    case DLL_THREAD_DETACH:
      break;
    case DLL_PROCESS_DETACH:
      TerminateThread(hThd, 0);
      break;
    }
  return TRUE;
  }