#include<iostream>
using namespace std;
class A{
	public:
		 void f(){
			cout<<"AAAAAA"<<endl;
		}
		~A(){
			cout<<"����A"<<endl; 
		}
		
}; 
class B:public A{
	public:
		void f(){
			cout<<"BBBBBB"<<endl;
		}
		~B(){
			cout<<"����B"<<endl; 
		}
		
};
//1.ͨ���������������Ա�����͵��÷����Ա��������ͬ��
//2.�����Ǹ��Ի���A��ָ��Ϊ�����ĺ�����ָ�뼴�Ƕ���ĵ�ַ,
//������ݵĵ�ַ������B����C�Ķ���ĵ�ַ����ô�麯����ָ��Ҳ��ͬ�����õĳ�Ա����Ҳ�Ͳ�ͬ
int main(){
//	B b;
//	b.f();
//	A a=(A)b;
//	a.f();//������virtual�޹�
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
