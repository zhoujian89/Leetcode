#include<iostream>
using namespace std; 
/*�������� 
  1.���һ�����������ĳ�������Ĺ��ܣ����Ǳ���Գ�֮Ϊ��������
  ֻ��ҪΪ�������Ĳ�����()�������ؾͿ���
  2.�����������β��б��е���ĳ������ʱ������������һ���������ֺ������ܵĺ�������
  Ȼ�����β���ʹ����������������Ĺ��ܺͺ���ָ�������Ĺ�������ͬ�ģ����Ҹ��Ӱ�ȫ�� 
*/
class Func{
public:
	//��������Ҫ���ز�����() 
    int operator() (int a, int b)
    {
        cout<<a<<'+'<<b<<'='<<a+b<<endl;
        return a;
    }
};
//����func���к����Ĺ��� 
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
