#include "circle_area.h" 
#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

/*
 * Input():
 * ��������Բ�İ뾶�ķ����� 
 */

double Circle_area :: Input()
{
	double r;
	
	cout << "Please input the radius of a circle : ";  
	cin >> r;
	
	return r;
}

/*
 * Calculate():
 * ���ڼ���Բ������ķ����� 
 */

double Circle_area :: Calculate(double r)
{
	double S = 0;
	
	S = pi*r*r;
	
	return S;
}

