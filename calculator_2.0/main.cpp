#include "calculation.h"
#include "calculator.h"
#include "print.h"

#include<string>
#include<string.h>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;
int bitjudge=0;

int main(int argc,char*argv[])    //��ͨ������������ʱͨ��Input�������� 
{
    queue<string> que; // type:queue<string>
    
	Scan Sc;    // Define a "Scan" object:"Sc".
    Print Put;  // Define a "Print" object "Put".
    Calculation Ca; // Define a "Calculation" object "Ca".
    
    string str=argv[argc-1];  
    
    if(strcmp(argv[1],"-a")==0) //�ж��Ƿ�������'-a' 
    {
    	que.push(str);
    	Put.pout(que);    // printf que.
    }
    
    while(!que.empty())que.pop();  // ���que 
     
	que=Sc.ToStringQueue(argv[argc-1]);
    
    if(!que.empty()) 
    cout<<Ca.carryout(que)<<endl;
    else //���� 
    cout<<"error"<<endl;
    
    return 0;
}

