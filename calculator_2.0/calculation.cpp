//==============================//
//�������岿�֣�calculation     // 
//�ļ����ƣ�calculation.cpp     //
//���ߣ�031502209               //
//����ʱ�䣺2016/4/7            //
//���ͣ�qq952693358             //
//==============================//

//==================================//
//˵�����ò��ַ�Ϊ�����            //
//1.��ԭ����ʽ��ת����Ϊǰ׺���ʽ  //
//2.ǰ׺���ʽ�ļ���                //
//==================================//
#include "calculation.h"
#include<stack>
#include<queue>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>

//======priority=======//
//˵���������ж����ȼ� //
//=====================// 
int priority(string s)
{
    if(s=="(" || s== ")")return 0;
	if(s=="+" || s=="-")return 1;
	if(s=="*" || s=="/")return 2;
}

//======calculate======//
//˵�������ڼ���       //
//=====================// 
double calculate(string s,double a,double b)//double
{	
	if(s=="+")return b+a;
	if(s=="-")return b-a;
	if(s=="*")return b*a;
	
	if(s=="/" && a!=0)return b*1.0/a;
	else return 0;
}
//========��������========// 
double Calculation::carryout(queue<string> que)
{	
	stack<string> sign1,sign2;
	stack<string> signstore;//���� 
	
	string s;
	string que_s;
	string sign1_top;
	
	if(que.front()=="-")
	signstore.push("0");
	
	//==========================//
	//��'='��ʼ�����������     // 
	//������һ��ջsignstoreʵ�� //
	//==========================//
	while(!que.empty())
	{
		signstore.push(que.front());
		que.pop();
	}
	
//-------------------------BEGIN-------------------------//	
    
    //======����1======//
	//ת��Ϊǰ׺���ʽ //
	//=================// 
	while(!signstore.empty())
	{
		s=signstore.top();
	    signstore.pop();
		
		if(s=="=")continue;
		if(s=="+" || s=="-" || s=="*" || s=="/" || s=="(" || s==")")
		{
			//=============˵��=============// 
			//��������������:             //
			//(1)s�����ȼ�����sign1ջ��Ԫ�� //
			//(2)s==")"                     //
			//(3)sign1Ϊ��ջ                //
			//��:sֱ��push��sign1           //
			//==============================//
			
			//sign1Ϊ��ջ  
			if(sign1.empty())
			{
				sign1.push(s);
				
				continue;
			}
			
			//s==")"
			if(s==")")
			{
				sign1.push(s);
				
				continue;
			}
			
			//=============˵��=============// 
			//�������������:               //
			//��sign1������ַ�push��sign2  //
			//ֱ������������                //
			//==============================//
			if(s=="(")
			{
			    while(sign1.top()!=")")
			    {
			    	sign2.push(sign1.top());
			    	
			    	sign1.pop();
			    }
				sign1.pop();//�����ų�ջ 
				continue;
			}
			
			//s�����ȼ�����sign1ջ��Ԫ�� //
			
			if(priority(s) > priority(sign1.top()))
			{
				sign1.push(s);
			    
				continue;
			}
		    
			//s�����ȼ�С��sign1ջ��Ԫ��//
			
			//==============˵��===============//
			//������s�����ȼ�С��ջ��Ԫ��ʱ    // 
			//��sign1������ַ���ջ��          //
			// push��sign2                     //
			//ֱ��ջ��Ԫ�����ȼ�����s����ջ��  // 
			//=================================// 
			else if(priority(s) < priority(sign1.top()))
			{
				while(priority(s) < priority(sign1.top()))
				{
					sign1_top=sign1.top();
					
				    sign1.pop();
				    
				    sign2.push(sign1_top);
				    
				    if(sign1.empty())break;
				}
				sign1.push(s);
				continue;
			}
			else //���ȼ���ͬ �ҷ�"("����")"ֱ����sign1 
			{
				if(s=="+" || s=="-" || s=="*" || s=="/")
				sign1.push(s);
			}
		}
		else //��������ֵĻ� push��sign2 
		{
			sign2.push(s);
			continue;
		}
	}
	
	//��sign1��ʣ��Ĳ��ְ�˳��push��sign2 
	while(!sign1.empty())
	{
		sign2.push(sign1.top());
		sign1.pop();
	}
	
	//ת��Ϊǰ׺���ʽ ��� 
	
//-------------------------END-------------------------//	
	
	/*while(!sign2.empty())
	{
		cout<<sign2.top();
		sign2.pop();
	}
	
	cout<<endl;*/
	
	//========����2========// 
	//����ǰ׺���ʽ       // 
	//=====================//
	
	//sign2������->sign_2 
    stack<string> sign_2;
	
	while(!sign2.empty())
	{
		sign_2.push(sign2.top());
		
		sign2.pop();
	}
	
	//ʹ��stringstream ���ַ���ת��Ϊ���� 
	stringstream stream;
	double number;
	stack<double> numberstore;//�洢���ֵ�ջ 
	string s2;
	
	numberstore.push(0);
	//���㲿�� 
	while(!sign_2.empty())
	{
		s2=sign_2.top();
		sign_2.pop();
		
		//��������� ��ȡ��numberstoreջ������Ԫ�ؽ��м���
		//���push��numberstore 
		if(s2=="+" || s2=="-" || s2=="*" || s2=="/")
		{
			double number1;
			number1=numberstore.top();
			numberstore.pop();
			
			double number2;
			number2=numberstore.top();
			numberstore.pop();
			
			double cal_number;
			cal_number=calculate(s2,number2,number1);
			
			numberstore.push(cal_number);
			
			continue;
		}
		else //���������� ת��Ϊ����֮����ջ 
		{
			stream.str(s2);
			stream>>number;
			
			numberstore.push(number);
			stream.clear();
			
			continue;
		}
	}
	
	double value=0;
	
	if(!numberstore.empty())
	value=numberstore.top();//ջ��Ԫ�ؼ����ս��
	 
	return value;
}

//-3+(9-((10-8)+(9-8*6/2+3)-10*10)*(8-(1+8/4+2)))+5*(1+(2+3)/5)/3
