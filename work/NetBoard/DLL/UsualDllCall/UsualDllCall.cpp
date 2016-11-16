//#include <iostream>
//using namespace std;
//#include <Windows.h>
//typedef void(CALLBACK* LPFUNPRINT)();
//void main ()
//{
//    //LPCWSTR path ;
//    //memcpy(path, , sizeof( "..\\Debug\\usualDll.dll " ) ) ;
//    HINSTANCE hDll;
//    LPFUNPRINT lpfunprint;
//    //FARPROC lpfp;
//    hDll = LoadLibrary( /*(LPCWSTR)(LPCWSTR)*/("usualDLL.dll") );
//    DWORD le = ::GetLastError();
//    if( hDll != NULL )
//    {
//        lpfunprint = (LPFUNPRINT)GetProcAddress( hDll, "print" );
//        le = ::GetLastError();
//        lpfunprint();
//    }
//}
#include <stdio.h>
#include <windows.h>
#include "UsualDll.h"
typedef int(*lpAddFun)(int, int); //宏定义函数指针类型
int main(int argc, char *argv[])
{
    HINSTANCE hDll; //DLL句柄
    lpAddFun addFun; //函数指针"..\\Debug\\usualDLL.dll"
    hDll = LoadLibrary("usualDLL");
    DWORD le = ::GetLastError();
    if (hDll != NULL)
    {
        addFun = (lpAddFun)GetProcAddress(hDll, "add");
        le = ::GetLastError();
        if (addFun != NULL)
        {
            int result = addFun(2, 3);
            printf("%d", result);
        }
        
        int result = add(2, 3);
        printf("%d", result);
        
        FreeLibrary(hDll);
    }
    return 0;
}