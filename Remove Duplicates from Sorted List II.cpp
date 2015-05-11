#include<iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
int main(){
	//ListNode * head,*p;
	//head=new ListNode(1);
//	p=head;
//	p->next=new ListNode(1);
//	p-
 int i=1;
 while(i<=5){
 	while(i<=2) {
 	cout<<i<<endl;
 	i++;
 }
 cout<<"ddd"<<endl;
 i++;
 	if(i==3){
 		continue;//直接从循环while(i<=5){}从头开始执行 
 //	i++;
 	}
 	cout<<"kkk"<<endl;
 	
 }
	return 1;
} 
