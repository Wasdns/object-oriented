//==============================//
//�ļ����ƣ�calculator.h        //
//���ߣ�031502209               //
//����ʱ�䣺2016/3/30           //
//���ͣ�qq952693358             //
//==============================//
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<string>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;

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
        queue<string>ToStringQueue(string input);
};

#endif // CALCULATOR_H
