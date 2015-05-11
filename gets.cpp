#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	/*
	从标准输入设备读字符串函数。可以无限读取，不会判断上限，以回车结束读取，
	所以程序员应该确保buffer的空间足够大，以便在执行读操作时不发生溢出。
	如果gets()函数读取的字符串长度大于被赋值数组的长度，就会引起溢出
	gets(s)函数与scanf("%s",s)相似，但不完全相同，使用scanf("%s",s) 函数输入字符串时存在一个问题，
	就是如果输入了空格会认为字符串结束，空格后的字符将作为下一个输入项处理，
	但gets()函数将接收输入的整个字符串直到遇到换行为止。
	*/
	char str[5];//最多只能输入4个字符，最后一个字符自动填上\0 
    gets(str);
    char *p=str;
    while(*p!='\0'){
    	cout<<*p<<endl;
    	p++;
	}
    cout<<str<<endl;
	return 1;
}
