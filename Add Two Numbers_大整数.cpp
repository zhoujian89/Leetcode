#include<math.h>
#include<queue> 
#include<iostream>
#include<algorithm>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
queue<int> getVal(ListNode * head){
    queue<int> s;
  	ListNode *p=head;
  	while(p!=NULL){
  		s.push(p->val);
		p=p->next;	
  	}
  	return s;
  }
  ListNode * createList(ListNode *l1, ListNode *l2){
  	queue<int> s1=getVal(l1);
  //	cout<<s1.size()<<endl;
  	queue<int> s2=getVal(l2);
  //	cout<<s2.size()<<endl;
  	ListNode *head=new ListNode(-1),*q=head;
  	int flag=0;//代表进位
	  while(!s1.empty()&&!s2.empty()){
	  	int temp=s1.front()+s2.front();
	  	if(temp+flag<=9){
	  	ListNode *p=new ListNode(temp+flag); 
  		q->next=p;
  		q=q->next;
  		flag=0;
	  	}
	  	else{
		 ListNode *p=new ListNode((temp+flag)%10);
		 flag=1;
		q->next=p;
  		q=q->next;		
	  	}
	  	s1.pop();
	  	s2.pop();
	  } 
	  while(!s1.empty()){
	  	int temp=s1.front();
	  	if(temp+flag<=9){
	  	ListNode *p=new ListNode(temp+flag); 
  		q->next=p;
  		q=q->next;
  		flag=0;
	  	}
	  	else{
		 ListNode *p=new ListNode((temp+flag)%10);
		 flag=1;
		q->next=p;
  		q=q->next;		
	  	}
	  	s1.pop();
	  }
	   while(!s2.empty()){
	  	int temp=s2.front();
	  	if(temp+flag<=9){
	  	ListNode *p=new ListNode(temp+flag); 
  		q->next=p;
  		q=q->next;
  		flag=0;
	  	}
	  	else{
		 ListNode *p=new ListNode((temp+flag)%10);
		 flag=1;
		q->next=p;
  		q=q->next;		
	  	}
	  	s2.pop();
	  }
	  if(flag==1){
	  	ListNode *p=new ListNode(1);
	  	q->next=p;
	  	q=q->next;
	  }
	  return head->next;
  }
int main(){
	ListNode *l1=new ListNode(1);
	ListNode *l11=new ListNode(9);
	ListNode *l111=new ListNode(9);
	ListNode *l1111=new ListNode(9);
	ListNode *l11111=new ListNode(9);
	ListNode *l111111=new ListNode(9);
	ListNode *l1111111=new ListNode(9);
	ListNode *l11111111=new ListNode(9);
	ListNode *l111111111=new ListNode(9);
	ListNode *l2=new ListNode(9);
	l1->next=l11;
	l11->next=l111; 
	l111->next=l1111;
	l1111->next=l11111;
	l11111->next=l111111;
	l111111->next=l1111111;
	l1111111->next=l11111111;
	l11111111->next=l111111111;
	ListNode * head=createList(l1, l2);//addTwoNumbers(l1, l2);
	for(ListNode *p=head;p!=NULL;p=p->next){
		cout<<p->val<<endl;
	}
	return 1;
}
