#include<iostream>
#include<vector>
using namespace std;
class A{
	public:
		~A(){//若析构函数A不是虚函数，则为静态绑定，只析构A;A为虚函数，动态绑定，先析构子类，再析构父类 
			cout<<"A在析构"<<endl;
		}
};
class B:public A{
	public:
		~B(){
			cout<<"B在析构"<<endl;
		}
}; 
int main(){
	A * pa=new B();
	delete pa;
	return 1;
}
