// testImplicit.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Queue.h"

#pragma comment(lib,"labaOS.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	
	auto rty = TSQueue<int>::getTSQueue();
	rty->queue(56);
	int res = rty->dequeue();
	//delete rty;
	return 0;
}

