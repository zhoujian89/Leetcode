#include<iostream>
#include<stdio.h> 
using namespace std;
//#pragma pack(2)
struct stu{
	char sex;
	int length;
	char name[10];
};
struct A {  
    double a;  
    char b;  
    short c;  
};  
  
struct B {  
    char b;  
    double a;  
    short c;  
}; 

int main(){
	/*������x86�£�GCCĬ�ϰ�4�ֽڶ��룬������sex�����name����ֱ����������
	�����ֽ�ʹlength�������ṹ����롣��������sizeof(my_stu)��õ�����Ϊ20��������15*/
	
	//Ĭ�ϰ������ֽڶ���, ��#pragma pack(4) 
//	#pragma pack(1)    sizeof(stu)=15 
//#pragma pack(2)   sizeof(stu)=16 
	cout<<sizeof(stu)<<endl;
	
	
	/*...............................................*/ 
	cout<<sizeof(A)<<endl;
	cout<<sizeof(B)<<endl;
	return 1;
}

/*char             -128 ~ +127        (1 Byte)
short             -32767 ~ + 32768    (2 Bytes)
unsigned short     0 ~ 65536        (2 Bytes)
int             -2147483648 ~ +2147483647   (4 Bytes)
unsigned int         0 ~ 4294967295    (4 Bytes)
long == int
long long         -9223372036854775808 ~ +9223372036854775807    (8 Bytes)
double    float     1.7 * 10^308        (8 Bytes)*/
