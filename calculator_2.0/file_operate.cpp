#include "calculation.h"
#include "calculator.h"
#include "print.h"
#include "file_operate.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream> //ע:������Ҫ����ͷ�ļ�<fstream> 
using namespace std;

//==================================//
//˵����
//      �����ļ������������    
//==================================//

void File_Operate::Fileoperate()
{
	Scan Sc;    
    Print Put;  
    Calculation Ca;
	
	ifstream infile; 
    ofstream outfile;
    
    //���ļ� 
    infile.open(getsfile.c_str(),ios::in); 
    outfile.open(putsfile.c_str(),ios::out);
    	
    string get_str;
    	
    while(!infile.eof()) //δ�����ļ�β 
    {
    	getline(infile,get_str); //�������� 
    		
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
