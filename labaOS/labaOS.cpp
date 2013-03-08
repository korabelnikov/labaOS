
#include "stdafx.h"
#include "Queue.h"
#include <string.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;
char* intToText(int i)
{
	char* res = new char[30];
	itoa(i,res,30);
	return res;
}
int intFromText(char* c)
{
	return atoi(c);
}
char* charsToText(char* c)
{
	char *text = new char();
	memcpy(text,c,100);
	return text;
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*Queue<char*> *l = Queue<char*>::openFile(charsToText);
	char* w1 = l->dequeue();
	char* w2 = l->dequeue();
*/
	/*q->queue(1);
	q->queue(2);
	q->queue(3);
	q->saveFile(intToText);
	q = q->openFile(intFromText);
	*/return 0;
}
extern __declspec(dllexport) void menu()
{
	Queue<int> *q;

	cout<<"1 - create a new \n 2 - open exist \n 3 - queue \n 4 - dequeue \n save to file \n e - exit";
	char c=0;
	while (c!='e')
	{
	cin>>c;
	int res;
		switch (c)
		{
		//system("pause");
		case '1':
			q = new Queue<int>();
			break;
		case '2':
			q = Queue<int>::openFile(intFromText);
			break;
		case '3':
			cout<<"Input value \n";
			int in;
			cin>>in;
			q->queue(in);
			break;
		case '4':
			res = q->dequeue();
			cout<<res;
			break;
		case 'e':
			return;
		}
	}
		if (q!=NULL) delete q;

}

