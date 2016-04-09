//==============================//
//�������岿�֣�calculator      // 
//�ļ����ƣ�calculator.cpp      //
//���ߣ�031502209               //
//����ʱ�䣺2016/4/2  4/5       //
//���ͣ�qq952693358             //
//==============================//

//==================================//
//˵�����ò��ֶ������[input]�ַ��� //
//������һ���ַ��ı�����<�ж�>:     //
// <�жϴ�>                       //
// <�ж�С��>                       //
//�Լ�һ�����������жϣ�          //
//bool error                        //  
//==================================//
#include "calculator.h"
#include<string>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;
extern int bitjudge;

// type:queue<string>
queue<string> Scan::ToStringQueue(string input)
{
    string s;  //Define a string "s".
    
    queue<string> que;   //Define a queue "que".
    
    bool error=true;    //Define a bool "error" ���ڼ����Ƿ����.
    
    bool istrue=true;   //Define a bool "istrue" ��������'-'�� 
    //======istrue˵��=======//
	//istrue=false:          //
	//���������������������� // 
	//istrue=true:           //
	//����������             // 
    //=======================//
    
	int n;
	int i,j;
	int judge=0;
	
    n=input.size();  //Define int n = string's length.
    
    for(i=0;i<n;i++)     
    {
    	//=====================//
    	//�жϣ�               //
		//���������Ƿ񳬹�ʮλ //
    	//=====================//
    	if(bitjudge>=10)
    	{
    		cout<<"error"<<endl;
    		error=false;  //input error
    		break;
    	}
    	
    	//===================//
    	// <�жϴ�>��      // 
    	//˵���������˷���'-'//
		//��input[i] == '-'  //
		//===================//
        if(input[i]=='-')
        {
        	bitjudge=0;   //stop the count
        	
            judge=1;      //judge=1��������'-'  
            
            if(s!="") 
            {
            	que.push(s);  //��֮ǰ�ַ����洢������push 
            	istrue=false; //istrue��false �������������� 
            }
            
            s.clear();    //����ַ���s 
            
            s+=input[i]; 
            continue;
        }
        
        //=====================//
    	// <�жϴ�>��        // 
    	//˵����û����������'-'//
		//��input[i] != '-'    //
		//=====================//
        else
        {
        	//===========================//
        	// <�ж�С��>:               // 
			//input[i-1] == '-';         //
			//��֮ǰ�����˷���'-'        //  
			//(ע����ʱ��judge=1����ʾ ) //
			//===========================//
			
            if(judge==1)    
            {
            	//1.��ʱinput[i]��������//
                if(input[i]=='('||input[i]==')'
				||input[i]=='+'||input[i]=='*'||input[i]=='/'||input[i]=='=')
                {
                	bitjudge=0;  //stop the count 
                	
                    judge=0;
                    
                    if(s!="")
                    {
                    	que.push(s);
                    	istrue=true; //'-'�ź���û���������� ת��true 
                    }
                    
                    s.clear();
                    
                    s+=input[i];
                    
                    que.push(s); 
                    s.clear();     
                }
                
                //2.��ʱinput[i]������// 
                else
                {
                	bitjudge++;
                	
                	if(istrue)        //����������������� s+='-' 
                	{
                		s+=input[i];
                		
                		istrue=false; //'-'���Ѿ����й��� 
                		              //��ʱ��false��������������� 
                	}
                    else
                    {
                    	if(s=="-")       //���'-'���������������� 
                    	{
                    		que.push(s); //push'-' 
                    	    s.clear();
                    	}
                    	
                    	s+=input[i]; 
                    }
                    continue;
                }
            }
            
            //===========================//
        	// <�ж�С��>:               // 
			//input[i-1] != '-';         //
			//��֮ǰû����������'-'      //  
			//(ע����ʱ��judge=0����ʾ ) //
			//===========================//

            else   
            {
            	//1.��ʱinput[i]��������//
                if(input[i]=='('||input[i]==')'
				||input[i]=='+'||input[i]=='*'||input[i]=='/'||input[i]=='=')
                {	
                    bitjudge=0;  //stop the count
                    
                    if(input[i]=='(')  //������������ istrue��true 
                    istrue=true; 
                    else istrue=false; //�������Ų����� 
					 
                	if(s!="")
                    que.push(s);
                    s.clear();
                    
                    s+=input[i];
                    
                    que.push(s);
                    s.clear();
                }
                
                //2.��ʱinput[i]������// 
                else
                {
                	bitjudge++;
                    s+=input[i];
                    continue;
                }
            }
            
        }
    }
    
    if(s!="" && error)
    que.push(s);
    
    s.clear();
    
    return que;
}


