#pragma once
#include "queue.h"
#ifdef DLL_NONCLIENT_BUILD // в директивах препроцессора проекта с dll нужно прописать DLL_NONCLIENT_BUILD
#   define DLL __declspec(dllexport)
#else
#   define DLL __declspec(dllimport)
#endif

template<typename T> DLL class TSQueue :
	public Queue<T>
{
	Queue<char*>* callQueue;
	void handler();
	DWORD threadId;
	HANDLE thread;
	TSQueue(void);
public:
	~TSQueue(void);
	TSQueue<T>* getTSQueue(void);

};

