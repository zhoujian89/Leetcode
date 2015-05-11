#include<string> 
#include<cstring>
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
//vector 的 clear 不影响 capacity , 你应该 swap 一个空的 vector
/*
当vector、string大量插入数据后，即使删除了大量数据（或者全部都删除，即clear）
并没有改变容器的容量（capacity），所以仍然会占用着内存。 
为了避免这种情况，我们应该想办法改变容器的容量使之尽可能小的符合当前 
数据所需（shrink to fit）
*/ 

/*
vector<type> v; 
//.... 这里添加许多元素给v 
//.... 这里删除v中的许多元素 
vector<type>(v).swap(v); 
//此时v的容量已经尽可能的符合其当前包含的元素数量 
//对于string则可能像下面这样 
string(s).swap(s); 
*/ 

/*
即先创建一个临时拷贝与原先的vector一致，值得注意的是，此时的拷贝其容量是尽可能小的符合所需数据的。
紧接着将该拷贝与原先的vector v进行 交换。好了此时，执行交换后，临时变量会被销毁，内存得到释放。
此时的v即为原先 的临时拷贝，而交换后的临时拷贝则为容量非常大的vector（不过已经被销毁）
*/

/*
并不是所有的STL容器的clear成员函数的行为都和vector一样。事实上，
其他容器的clear成员函数都会释放其内存。
比如另一个和vector类似的顺序容器deque
*/
vector <string> v; 
char ch; 
int main(){
	/*
	vector()使用vector的默认构造函数建立临时vector对象，再在该临时对象上调用swap成员，
	swap调用之后对象myvector占用的空间就等于一个默认构造的对象的大小，
	临时对象就具有原来对象v的大小，而该临时对象随即就会被析构，从而其占用的空间也被释放。
	*/
	/*
	并不是所有的STL容器的clear成员函数的行为都和vector一样。事实上，
	其他容器的clear成员函数都会释放其内存。比如另一个和vector类似的顺序容器deque。
	*/ 
	for(int i=0; i<1000000; i++) 
        v.push_back("abcdefghijklmn"); 
   vector<string>().swap(v);
   cout << "非不用clear，直接swap,容量为： " <<v.capacity()<< endl; 
    //cin >> ch; 
    // 此时检查内存情况 占用54M 
     vector<string> ve(v);//不是匿名对象 
     cout << "非匿名对象ve的容量为： " << ve.capacity() << endl; 
     cout << "clear之前，匿名对象的容量为： " << vector<string>(v).capacity() << endl; 
     v.clear(); //任然持有内存，没有释放 
     cout << "clear之后，匿名对象的容量为： " << vector<string>(v).capacity() << endl; 
    // 此时再次检查， 仍然占用54M 
    cout << "Vector 的 容量为： " << v.capacity() << endl; 
    // 此时容量为 1048576 
   cout << "Vector 的 容量为： " << vector<string>(v).capacity() << endl; 
    vector<string>(v).swap(v); 
  
    cout << "Vector 的 容量为" << v.capacity() << endl; 
    // 此时容量为0 
   
    // 检查内存，释放了 10M+ 即为数据内存 
    
	
} 
