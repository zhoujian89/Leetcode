#include<iostream>
#include<vector>
using namespace std;
class A{
	public:
		~A(){//����������A�����麯������Ϊ��̬�󶨣�ֻ����A;AΪ�麯������̬�󶨣����������࣬���������� 
			cout<<"A������"<<endl;
		}
};
class B:public A{
	public:
		~B(){
			cout<<"B������"<<endl;
		}
}; 
int main(){
	A * pa=new B();
	delete pa;
	return 1;
}
