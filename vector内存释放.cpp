#include<string> 
#include<cstring>
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
//vector �� clear ��Ӱ�� capacity , ��Ӧ�� swap һ���յ� vector
/*
��vector��string�����������ݺ󣬼�ʹɾ���˴������ݣ�����ȫ����ɾ������clear��
��û�иı�������������capacity����������Ȼ��ռ�����ڴ档 
Ϊ�˱����������������Ӧ����취�ı�����������ʹ֮������С�ķ��ϵ�ǰ 
�������裨shrink to fit��
*/ 

/*
vector<type> v; 
//.... ����������Ԫ�ظ�v 
//.... ����ɾ��v�е����Ԫ�� 
vector<type>(v).swap(v); 
//��ʱv�������Ѿ������ܵķ����䵱ǰ������Ԫ������ 
//����string��������������� 
string(s).swap(s); 
*/ 

/*
���ȴ���һ����ʱ������ԭ�ȵ�vectorһ�£�ֵ��ע����ǣ���ʱ�Ŀ����������Ǿ�����С�ķ����������ݵġ�
�����Ž��ÿ�����ԭ�ȵ�vector v���� ���������˴�ʱ��ִ�н�������ʱ�����ᱻ���٣��ڴ�õ��ͷš�
��ʱ��v��Ϊԭ�� ����ʱ�����������������ʱ������Ϊ�����ǳ����vector�������Ѿ������٣�
*/

/*
���������е�STL������clear��Ա��������Ϊ����vectorһ������ʵ�ϣ�
����������clear��Ա���������ͷ����ڴ档
������һ����vector���Ƶ�˳������deque
*/
vector <string> v; 
char ch; 
int main(){
	/*
	vector()ʹ��vector��Ĭ�Ϲ��캯��������ʱvector�������ڸ���ʱ�����ϵ���swap��Ա��
	swap����֮�����myvectorռ�õĿռ�͵���һ��Ĭ�Ϲ���Ķ���Ĵ�С��
	��ʱ����;���ԭ������v�Ĵ�С��������ʱ�����漴�ͻᱻ�������Ӷ���ռ�õĿռ�Ҳ���ͷš�
	*/
	/*
	���������е�STL������clear��Ա��������Ϊ����vectorһ������ʵ�ϣ�
	����������clear��Ա���������ͷ����ڴ档������һ����vector���Ƶ�˳������deque��
	*/ 
	for(int i=0; i<1000000; i++) 
        v.push_back("abcdefghijklmn"); 
   vector<string>().swap(v);
   cout << "�ǲ���clear��ֱ��swap,����Ϊ�� " <<v.capacity()<< endl; 
    //cin >> ch; 
    // ��ʱ����ڴ���� ռ��54M 
     vector<string> ve(v);//������������ 
     cout << "����������ve������Ϊ�� " << ve.capacity() << endl; 
     cout << "clear֮ǰ���������������Ϊ�� " << vector<string>(v).capacity() << endl; 
     v.clear(); //��Ȼ�����ڴ棬û���ͷ� 
     cout << "clear֮���������������Ϊ�� " << vector<string>(v).capacity() << endl; 
    // ��ʱ�ٴμ�飬 ��Ȼռ��54M 
    cout << "Vector �� ����Ϊ�� " << v.capacity() << endl; 
    // ��ʱ����Ϊ 1048576 
   cout << "Vector �� ����Ϊ�� " << vector<string>(v).capacity() << endl; 
    vector<string>(v).swap(v); 
  
    cout << "Vector �� ����Ϊ" << v.capacity() << endl; 
    // ��ʱ����Ϊ0 
   
    // ����ڴ棬�ͷ��� 10M+ ��Ϊ�����ڴ� 
    
	
} 
