#include<iostream>
using namespace std;
#pragma once 

#ifndef _USUAL_DLL_H_
#define _USUSL_DLL_H_
#endif

#ifdef _USUAL_DLL_
#define USUAL_DLL_API _declspec( dllimport )
#else 
#define USUAL_DLL_API _declspec( dllexport )
#endif 

/*#ifndef _cplusplus
extern C {
#endif*/ 
USUAL_DLL_API void print();
USUAL_DLL_API int add( int , int );

//#endif 