
//C++只关心你的指针类型，不关心指针指向的对象是否有效
//静态类型：对象在声明时采用的类型，在编译期既已确定；
//动态类型：通常是指一个指针或引用目前所指对象的类型，是在运行期决定的；
//静态绑定：绑定的是静态类型，所对应的函数或属性依赖于对象的静态类型，发生在编译期；
//动态绑定：绑定的是动态类型，所对应的函数或属性依赖于对象的动态类型，发生在运行期；

/*1. 如果基类A中的func不是virtual函数，那么不论pa、pb、pc指向哪个子类对象，对func的调用都是在定义pa、pb、pc时的静态类型决定，早已在编译期确定了。
    同样的空指针也能够直接调用no-virtual函数而不报错（这也说明一定要做空指针检查啊！），因此静态绑定不能实现多态；*/

/*
2. 如果func是虚函数，那所有的调用都要等到运行时根据其指向对象的类型才能确定，比起静态绑定自然是要有性能损失的，但是却能实现多态特性；

 本文代码里都是针对指针的情况来分析的，但是对于引用的情况同样适用。

至此总结一下静态绑定和动态绑定的区别：
1. 静态绑定发生在编译期，动态绑定发生在运行期；

2. 对象的动态类型可以更改，但是静态类型无法更改；

3. 要想实现动态，必须使用动态绑定；

4. 在继承体系中只有虚函数使用的是动态绑定，其他的全部是静态绑定；

 建议：

绝对不要重新定义继承而来的非虚(non-virtual)函数（《Effective C++ 第三版》条款36），
因为这样导致函数调用由对象声明时的静态类型确定了，而和对象本身脱离了关系，
没有多态，也这将给程序留下不可预知的隐患和莫名其妙的BUG；*/

/*另外，在动态绑定也即在virtual函数中，要注意默认参数的使用。当缺省参数和virtual函数一起使用的时候一定要谨慎，不然出了问题怕是很难排查。
看下面的代码：*/
#include<iostream>
using namespace std;
/*******************静态绑定，在编译时确定，只关心指针指向类型，不关心指向的对象.*****************/
/********************情况1*****************/
/*１：查找p的类型，发现它有一个非虚的成员函数叫foo。（编译器干的）
２：找到了，在这里生成一个函数调用，直接调A::foo(p)。
所以到了运行时，由于foo()函数里面并没有任何需要解引用p指针的代码，
所以真实情况下也不会引发segment fault。这里对成员函数的解析，
和查找其对应的代码的工作都是在编译阶段完成而非运行时完成的，
这就是所谓的静态绑定，也叫早绑定。 */
class A{
	public:
		void foo(){
			cout<<"foo"<<endl;
		}
		void func(){
			cout<<"func"<<endl;
		}
}; 
/*int main(){
	A *p=NULL;
	p->foo();
	p->func();
	return 1;
}*/
/*******************情况2静态绑定由编译器决定与多态无关*****************/
class B{
	public:
		virtual void f(){
			cout<<"BBBBBBBBB"<<endl;
		}
};
class C:public B{
	public:
		void f(){
			cout<<"CCCCCCCCCCC"<<endl;
		}
		
};
/*int main(){
	//无virtual静态绑定 
	B *pb=new B();
	C *pc=new C();
	pb=(B*)pc;
	pb=pc; 
	pb->f();
	//静态类型永远都是B*，不管其指向的是哪个子类，都是直接调用B::f()；
    pc=(C*)pb;
	pc->f();	
	return 1;
}*/
/*int main(){
	//多态 
	B *pb=new B();
	C *pc=new C();
	pb=(B*)pc;
	pb->f();
	//多态
	B *pb1=new C();
	pb1->f();
	
	B b;
	C c;
	b=(B)c;//类型只能向上转 
	b.f(); 
	
	B b1;
	C c1;
//	c1=(C)b1;//编译出错 
//	c1.f(); 

    B * pb2=new B();
	C * pb3=new C(); 
//	pb2=(B *)pb3;//或者 pb2=pb3 
//	pb2->f();//动态绑定 
    pb3=(C *)pb2;//动态绑定 
  // pb3=pb2; 编译错误 
    pb3->f();
    return 1;
}*/
 
 /******************
 //绝对不要重新定义一个继承而来的virtual函数的缺省参数值，
 //因为缺省参数值都是静态绑定（为了执行效率），而virtual函数却是动态绑定 
 绝对不要重新定义一个继承而来的virtual函数的缺省参数值，因为缺省参数值都是静态绑定（
 为了执行效率），而virtual函数却是动态绑定
 *******************************/ 
 class E{
 	public:
 		virtual void func(int i=0){
 			cout<<"EEEEEEEEE: "<<i<<endl;
 		}
 };
  class F: public E{
 	public:
 		virtual void func(int j=1){
 			cout<<"FFFFFFFFF: "<<j<<endl;
 		}
 };
 int main(){
 	F * pf=new F();
 	E * pe=pf;
 	pf->func();
 	pe->func();
 	return 1;
 }
 /**区分动态绑定和静态绑定**/
 //1.不加virtual时，具体调用哪个版本的函数只取决于指针本身的类型，和指针所指对象的类型无关
 //2.加virtual，具体调用哪个版本的函数不取决于指针本身的类型，而取决于指针所指对象的类型
 
 
/*在基类用virtual声明成员函数为虚函数。
这样就可以在派生类中重新定义此函数，为它赋予新的功能，并能方便地被调用。在类外定义虚函数时，不必再加virtual。
在派生类中重新定义此函数，要求函数名、函数类型、函数参数个数和类型全部与基类的虚函数相同，并根据派生类的需要重新定义函数体。
C++规定，当一个成员函数被声明为虚函数后，其派生类中的同名函数都自动成为虚函数。因此在派生类重新声明该虚函数时，可以加virtual，也可以不加，但习惯上一般在每一层声明该函数时都加virtual，使程序更加清晰。如果在派生类中没有对基类的虚函数重新定义，则派生类简单地继承其直接基类的虚函数。
定义一个指向基类对象的指针变量，并使它指向同一类族中需要调用该函数的对象。
通过该指针变量调用此虚函数，此时调用的就是指针变量指向的对象的同名函数。*/
