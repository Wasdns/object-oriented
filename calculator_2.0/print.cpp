#include "print.h"
#include<stack>
#include<string>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;

//==========================//
//judgeerror������          //
//�ж�"("��")"�Ƿ�ƥ��      //
//��ƥ��Ļ����error       //
//==========================// 
bool judgeerror(stack<string> sign)
{
	string s_top; 
	stack<string> store; //��������push ��������pop 
	
    while(!sign.empty())
    {
    	s_top=sign.top();
    	sign.pop();
    	if(s_top==")")
    	{
    		store.push(s_top);
    		continue;
    	}
    	if(s_top=="(")
    	{
    		if(store.empty())return false; 
    		
    		store.pop();
    		continue;
    	}
    }
    if(store.empty())return true;
    else return false;
} 

void Print::pout(queue<string> que)
{
	stack<string> sign;   //���ڴ洢"(" �� ")" ,֮�����ƥ���ж� 
	
	queue<string> store;  
	store=que;  //������һ������ ��"("��")" 
	 
	while(!store.empty())
	{
		if(store.front()== "(" || store.front()==")")
		{
			sign.push(store.front()); //ѹ������ƥ���жϵ�ջ			
		}
		store.pop();
	}
	
	if(judgeerror(sign))    // "(" �� ")"ƥ�� ������� 
	{
		while(!que.empty()) // "que" is not empty
        {
            cout << que.front();
        
		    que.pop();
        }
	}
	else  // "(" �� ")" ƥ����� 
    {
    	cout<<"error"<<endl;
    }
}

