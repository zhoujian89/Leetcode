#include<iostream>
using namespace std; 
/*函数对象 
  1.如果一个对象具有了某个函数的功能，我们变可以称之为函数对象
  只需要为这个对象的操作符()进行重载就可以
  2.当我们想在形参列表中调用某个函数时，可以先声明一个具有这种函数功能的函数对象，
  然后在形参中使用这个对象，他所作的功能和函数指针所作的功能是相同的，而且更加安全。 
*/
class Func{
public:
	//函数对象要重载操作符() 
    int operator() (int a, int b)
    {
        cout<<a<<'+'<<b<<'='<<a+b<<endl;
        return a;
    }
};
//对象func具有函数的功能 
int addFunc(int a, int b, Func& func)
{
    func(a,b);
    return a;
}
int main(){
Func func;
addFunc(1,3,func);
	return 1;
} 
