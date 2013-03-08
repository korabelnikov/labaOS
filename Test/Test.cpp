// Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <winbase.h>
//#include "Queue.h"
char* textToText(char* text)
{
	return text;
}
int _tmain(int argc, _TCHAR* argv[])
{
	auto hLib= LoadLibrary(L"labaOS.dll");
	if (hLib==NULL) throw "dll not found";
	auto pFunction = GetProcAddress(hLib, "?menu@@YAXXZ");
	if (pFunction==NULL) throw "function not found";
	//Queue<int>* queue = (Queue<int>*)pFunction();///
	//queue->queue(3456);
	//int res = queue->dequeue();
	pFunction();
	FreeLibrary(hLib);
	return 0;

}

