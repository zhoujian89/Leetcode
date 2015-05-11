#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  ListNode * createList(ListNode *l1, ListNode *l2){
  	ListNode * p1=l1;
  	ListNode * p2=l2;
  	ListNode *head=new ListNode(-1),*q=head;
  	int flag=0;//�����λ
	  while(p1!=NULL&&p2!=NULL){
	  	int temp=p1->val+p2->val;
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
	  	p1=p1->next;
	  	p2=p2->next;
	  } 
	  while(p1!=NULL){
	  	int temp=p1->val;
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
	  	p1=p1->next;
	  }
	   while(p2!=NULL){
	  	int temp=p2->val;
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
	  	p2=p2->next;
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
