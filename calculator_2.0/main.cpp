#include "calculation.h"
#include "calculator.h"
#include "print.h"

#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <iostream>
#include <fstream> //ע:������Ҫ����ͷ�ļ�<fstream> 
using namespace std;
int bitjudge = 0;

int main(int argc,char*argv[]) 
{
	Scan Sc;    
    Print Put;  
    Calculation Ca;
    
    //�ж��Ƿ�Ϊ�ļ����� 
	bool need_file = false; 
	
    if(strcmp(argv[1],"-f") == 0)  
    {
    	need_file = true;
    }
    
    //��Ҫ�����ļ����� 
    if(need_file)  
    {
    	string getsfile = argv[argc-2];  //�����ļ��� 
    	string putsfile = argv[argc-1]; //����ļ��� 
		     	
    	ifstream infile; 
    	ofstream outfile;
    	
    	//���ļ� 
    	infile.open(getsfile.c_str(),ios::in); 
    	outfile.open(putsfile.c_str(),ios::out);
    	
    	string get_str;
    	
    	while(!infile.eof()) //δ�����ļ�β 
    	{
    		getline(infile,get_str,'\n'); //�������� 
    		
    		queue<string> que;
    		
    		que = Sc.ToStringQueue(get_str);
    		
    		double result=0;
    		
    		result = Ca.carryout(que);
    		
    		outfile << result << endl;
    	}
    	
    	//�ر��ļ� 
    	infile.close();
    	outfile.close();
    }
    
    //��������ļ����� 
    else
    {
    	queue<string> que;
    	
    	string str = argv[argc-1];  
    
        if(strcmp(argv[1],"-a") == 0) //�ж��Ƿ�������'-a' 
        {
    	    que.push(str);
    	    Put.pout(que);    // printf que.
        }
    
        while(!que.empty())
	    que.pop();  // ���que 
     
	    que = Sc.ToStringQueue(argv[argc-1]);
    
        if(!que.empty()) 
        cout << Ca.carryout(que) << endl;
        else //���� 
        cout << "error" << endl;
    }
    
    return 0;
}

