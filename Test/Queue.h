/////Description
/////Queue based on linked list
//
////debugInfo
////last modified 
////date 22.02.2013
////by solin
//// 0 errrors
//// 0 warnings
//
////change list
//// subject, reason, date, author
//// name of class, it's queuem, 26.02.13, solin 
//
////need to change
////subject, reason[, how]
//
////additionaly info
//////
#ifdef DLL_NONCLIENT_BUILD // в директивах препроцессора проекта с dll нужно прописать DLL_NONCLIENT_BUILD
#   define DLL __declspec(dllexport)
#else
#   define DLL __declspec(dllimport)
#endif

#include "StdAfx.h"
#pragma once

template<typename T>  class DLL Queue
{
public:
	int count;
	Queue();
	~Queue();
	void queue(T val);
	T dequeue();
	//win32;
	static Queue<T>* openFile(T(*fromText)(char*));
};
class DLL QueueInt : Queue<int>
{

};
//6fac.labs@gmail.com