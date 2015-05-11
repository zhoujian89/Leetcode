#include<iostream>
using namespace std;
class A{
	public:
		 void f(){
			cout<<"AAAAAA"<<endl;
		}
		~A(){
			cout<<"析构A"<<endl; 
		}
		
}; 
class B:public A{
	public:
		void f(){
			cout<<"BBBBBB"<<endl;
		}
		~B(){
			cout<<"析构B"<<endl; 
		}
		
};
//1.通过对象调用类的虚成员函数和调用非虚成员函数是相同的
//2.对于那个以基类A的指针为参数的函数，指针即是对象的地址,
//如果传递的地址是子类B或者C的对象的地址，那么虚函数表指针也不同，调用的成员函数也就不同
int main(){
//	B b;
//	b.f();
//	A a=(A)b;
//	a.f();//与有无virtual无关
    B *p2=new B();
    A *p3=p2;
    p3->f();
	A * p=new B();
	p->f();
	B *p1=new B();
	p1->f(); 
	delete p;
	delete p1;
	delete p3;
	return 1;
}
