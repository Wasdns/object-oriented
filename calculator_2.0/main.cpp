#include "calculation.h"
#include "calculator.h"
#include "print.h"
#include "file_operate.h" 
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <iostream>
using namespace std;

int bitjudge = 0;

int main(int argc,char*argv[]) 
{
    //�ж��Ƿ�Ϊ�ļ����� 
	bool need_file = false; 
	
    if(strcmp(argv[1],"-f") == 0)  
    {
    	need_file = true;
    }
    
    //��Ҫ�����ļ����� 
    if(need_file)  
    {
    	File_Operate FO;
    	FO.getsfile = argv[argc-2]; //�����ļ��� 
    	FO.putsfile = argv[argc-1]; //����ļ��� 
		
		FO.Fileoperate();
    }
    
    //��������ļ����� 
    else
    {
	    Scan Sc;    
        Print Put;  
        Calculation Ca;
    
    	queue<string> que;
    	
    	string str = argv[argc-1];  
    
        if(strcmp(argv[1],"-a") == 0) //�ж��Ƿ�������'-a' 
        {
    	    que.push(str);
    	    Put.pout(que); // printf que.
        }
    
        while(!que.empty())
	    que.pop(); // ���que 
     
	    que = Sc.ToStringQueue(argv[argc-1]);
    
        if(!que.empty()) 
        cout << Ca.carryout(que) << endl;
        else //���� 
        cout << "error" << endl;
    }
    
    return 0;
}

