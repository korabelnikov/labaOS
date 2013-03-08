
#include "StdAfx.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "string.h"
#include "Queue.h"
#pragma once

template<typename T>  class Queue
{
public:
	Queue()
	{
		head=NULL;
		count=0;
	}
	~Queue()
	{
		while(head)
			dequeue();
	}
	void queue(T val)
	{
		Node *node = new Node();
		node->val=val;
		node->next=NULL;
		if(!head)
		{
			head = node;
			last = node;
		}
		else
		{
			last->next=node;
			last = last->next;
		}
		this->count++;
	}
	T dequeue()
	{
		if (!head) throw "List is empty";
		T res = head->val;
		head=head->next;
		//mb erase memory
		count--;
		return res;
	}
	//win32
	void saveFile(char*(*toText)(T))
	{
		char* cstr = new char[0];
		cstr[0]=0;
		while(head!=NULL)
		{
			T temp = dequeue();
			char* text = toText(temp);
			unsigned int len = strlen(cstr)+strlen(text)+1;
			strcat_s(cstr,len,text);
			strcat_s(cstr,strlen(cstr)+4,"#$%");
		}
		HANDLE file = CreateFileA( "O:/2.txt"/*__FILE__*/, GENERIC_WRITE, FILE_SHARE_WRITE, 0,
			CREATE_ALWAYS, 0, 0 ) ;
		DWORD nb = 0 ;
		WriteFile(file,cstr,strlen(cstr),&nb,0);
		CloseHandle(file);
	}
	static Queue<T>* openFile(T(*fromText)(char*))
	{
		HANDLE file = CreateFileA( "O:/2.txt"/*__FILE__*/, FILE_READ_DATA, 0, 0,
			OPEN_ALWAYS, 0, 0 ) ;
		if (file==NULL) throw "file is not found";
		//assert( file != HANDLE(-1) ) ;
		HANDLE map = CreateFileMapping( file, 0, PAGE_READONLY, 0, 0, 0 );
		char* cstr = static_cast<char*>(MapViewOfFile( map, FILE_MAP_READ, 0, 0, 0 ) ) ;
		//
		Queue<T>* res = new Queue<T>();
		char* lexem = new char[0];
		char* cur = cstr;
		const char split[] = "#$%";
			char cstr_[100];
			if (strlen(cstr)>99) throw "";
			/*for (unsigned int i=0;i<strlen(cur)+1;i++)
			{*/
				memcpy(cstr_,cur,strlen(cur)+1);
			//}
			lexem = strtok_s(cstr_,split,&cur);/// here
			T val = fromText(lexem);
			res->queue(val);
		while(lexem!=NULL)
		{
			lexem = strtok_s(NULL,split,&cur);
			if (lexem==NULL) break;
			T val = fromText(lexem);
			res->queue(val);
		}
		UnmapViewOfFile(cstr) ;
		CloseHandle(map) ;
		CloseHandle(file) ;
		return res;	
	}
};
