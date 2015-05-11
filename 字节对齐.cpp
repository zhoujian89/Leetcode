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
	/*由于在x86下，GCC默认按4字节对齐，它会在sex后面跟name后面分别填充三个和
	两个字节使length和整个结构体对齐。于是我们sizeof(my_stu)会得到长度为20，而不是15*/
	
	//默认按照四字节对齐, 即#pragma pack(4) 
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
