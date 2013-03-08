#include "StdAfx.h"
#include "TSQueue.h"
#include <conio.h>
#include <windows.h>
#include <iostream>

template<typename T> TSQueue<T>::~TSQueue<T>(void)
{
	CloseHandle(thread);
	callQueue.~Queue();
}

 
template<typename T> static TSQueue<T>* TSQueue<T>::getTSQueue<T>(void)
{
	TSQueue<T>* res = new Queue<T>();
	res.callQueue = new Queue<char*>();
	res.thread = CreateThread(NULL, 0, handler, NULL, 0, &threadId);
}

template<typename T> void TSQueue<T>::handler<T>(void)
{
	while(true)
	{
		char* value =callQueue.dequeue();
		if (value!=NULL) 
			if (value=="\n"){
				T res = dequue();
				cout<< res;
			}
			else 
			{
				queue(value);
			}
	}
}
