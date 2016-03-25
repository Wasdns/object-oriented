//==============================//
//�ļ����ƣ�calculator.h 
//���ߣ�031502209 
//����ʱ�䣺2016/3/23 
//���ͣ�qq952693358 
//==============================//
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<string>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;

//==============================//
//class:Input 
//���������뺯��Get 
//�������ͣ�string
//˵��:���뺯����������������� 
//==============================//
class Input
{
    public:
        string Get();
};

//===============================//
//class:Print
//�������������Get 
//�������ͣ�queue<string> 
//˵�������������������������� 
//===============================//
class Print
{
    public:
        void pout(queue<string> que); // type:queue<string>
};

//===============================//
//class:Scan
//����������ToStringQueue 
//�������ͣ�queue<string> 
//˵�������������������������� 
//===============================//
class Scan
{
    // private section
    public:
        queue<string>ToStringQueue(string input);//type:queue<string>
};

#endif // CALCULATOR_H
