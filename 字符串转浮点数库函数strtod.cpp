//%f 对应 float
//%lf 对应 double
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	 char *endptr;
    char a[] = "12345.6789";
    char b[] = "1234.567qwer";
    char c[] = "-232.23e4";
    char d[]="12345   ";
    printf("a=%lf\n",strtod(a,NULL));
    printf("b=%lf\n",strtod(b,&endptr));
    printf("endptr=%s\n",endptr);
    printf("c=%lf\n",strtod(c,NULL));
    strtod(d,&endptr);
    printf("endptr=%s\n",endptr);
    //string转char * 
	string str="gdfd";
    const char *p=str.c_str(); 
    printf("p=%s\n",p);
    str.insert(0, "a");
    cout<<str<<endl;
	return 1;
}
