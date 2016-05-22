#include "calculator.h"
#include <string>
#include <queue>
#include <stdlib.h>
#include <iostream>
using namespace std;

//==================================//
//˵���� 
//     �ò��ֶ������[input]�ַ���
//     ������һ���ַ��ı�����<�ж�>:
//     <�жϴ�>
//     <�ж�С��>
//     �Լ�һ�����������ж�:
//     bool error
//==================================//

extern int bitjudge;

queue<string> Scan::ToStringQueue(string input)
{
    string s;  
    
    queue<string> que;
    
    bool error = true; //���ڼ����Ƿ����.
    
    bool is_Connected = true; //��������'-'�� 
    //======is_Connected˵��=======//
	//is_Connected = false:        
	//    ����������������������        
	//is_Connected = true:         
	//    ����������                    
    //=============================//
    
	int n;
	int i,j;
	int judge = 0;
	
    n = input.size();
    
    for(i = 0;i < n; i++)     
    {
    	//=====================//
    	//�жϣ�               
		//    ���������Ƿ񳬹�ʮλ 
    	//=====================//
    	if(bitjudge >= 10)
    	{
    		cout << "error" << endl;
    		error = false; //input error
    		break;
    	}
    	
    	//===================//
    	// <�жϴ�>��      
    	//˵����
		//    �����˷���'-'
		//    ��input[i] == '-'  
		//===================//
        if(input[i] == '-')
        {
        	bitjudge = 0; //stop the count
        	
            judge = 1; //judge = 1��������'-'  
            
            if(s != "") 
            {
            	que.push(s);  //��֮ǰ�ַ����洢������push 
            	is_Connected = false; //is_Connected��false �������������� 
            }
            
            s.clear();
            
            s += input[i]; 
            continue;
        }
        
        //=====================//
    	// <�жϴ�>��         
    	//˵����
		//    û����������'-'
		//    ��input[i] != '-'    
		//=====================//
        else
        {
        	//===========================//
        	// <�ж�С��>:               
			//    input[i-1] == '-';         
			//    ��֮ǰ�����˷���'-'         
			//    (ע����ʱ��judge=1����ʾ ) 
			//===========================//
			
            if(judge == 1)    
            {
            	//1.��ʱinput[i]��������//
                if(input[i] == '(' || input[i] == ')'
				|| input[i] == '+' || input[i] == '*'
				|| input[i] == '/' || input[i] == '=')
                {
                	bitjudge = 0; //stop the count 
                	
                    judge = 0;
                    
                    if(s != "")
                    {
                    	que.push(s);
                    	is_Connected = true; //'-'�ź���û���������� ת��true 
                    }
                    
                    s.clear();
                    
                    s += input[i];
                    
                    que.push(s); 
                    s.clear();     
                }
                
                //2.��ʱinput[i]������// 
                else
                {
                	bitjudge++;
                	
                	if(is_Connected) //����������������� s+='-' 
                	{
                		s += input[i];
                		
                		is_Connected = false; //'-'���Ѿ����й��� 
                		//��ʱ��false��������������� 
                	}
                    else
                    {
                    	if(s == "-") //���'-'���������������� 
                    	{
                    		que.push(s); //push'-' 
                    	    s.clear();
                    	}
                    	
                    	s += input[i]; 
                    }
                    continue;
                }
            }
            
            //===========================//
        	// <�ж�С��>:                
			//    input[i-1] != '-';         
			//    ��֮ǰû����������'-'        
			//    ע����ʱ��judge=0����ʾ 
			//===========================//

            else   
            {
            	//1.��ʱinput[i]��������//
                if(input[i] == '(' || input[i] == ')'
				|| input[i] == '+' || input[i] == '*'
				|| input[i] == '/' || input[i] == '=')
                {	
                    bitjudge = 0; //stop the count
                    
                    if(input[i] == '(') //������������ is_Connected��true 
                    is_Connected = true; 
                    else is_Connected = false; //�������Ų����� 
					 
                	if(s != "")
                    que.push(s);
                    s.clear();
                    
                    s += input[i];
                    
                    que.push(s);
                    s.clear();
                }
                
                //2.��ʱinput[i]������// 
                else
                {
                	bitjudge++;
                    s += input[i];
                    continue;
                }
            }
            
        }
    }
    
    if(s != "" && error)
    que.push(s);
    
    s.clear();
    
    return que;
}

