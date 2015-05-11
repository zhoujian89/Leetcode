#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  int getLen(ListNode * head){
  	ListNode * p=head;
  	int count=0;
  	while(p!=NULL){
  		count++;
  		p=p->next;
  	}
  	return count-1;   
  } 
  int getVal(ListNode * head){
  	int result=0;
  	int count=getLen(head);
  	int num=0;
  	ListNode *p=head;
  	while(p!=NULL&&num<=count){
  	  result=result+p->val*pow(10,num);
		num++;
		p=p->next;	
  	}
  	return result;
  }
  ListNode * createList(int val){
  	int temp=0;
  	ListNode *head=new ListNode(-1),*q=head;
  	//ͷ�巨 
  	while(val>0){
  		temp=val%10;
  		//cout<<temp<<endl;
  		ListNode *p=new ListNode(temp); 
  		q->next=p;
  		q=q->next;
  	//	p->next=head->next;
		//head->next=p; 
  		val=val/10;	
  	}
  	return head->next; 
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
       int val=getVal(l1)+getVal(l2);
       //cout<<val<<endl;
	   return createList(val); 
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
	ListNode *l1111111111=new ListNode(9);
//	ListNode *l11111111111=new ListNode(9);
//	ListNode *l111111111111=new ListNode(9);
	ListNode *l2=new ListNode(9);
	//ListNode *l22=new ListNode(6);
	//ListNode *l222=new ListNode(4);
	l1->next=l11;
	l11->next=l111; 
	l111->next=l1111;
	l1111->next=l11111;
	l11111->next=l111111;
	l111111->next=l1111111;
	l1111111->next=l11111111;
	l11111111->next=l111111111;
	//l2->next=l22;
	//l22->next=l222; 
	ListNode * head=addTwoNumbers(l1, l2);//addTwoNumbers(l1, l2);
	for(ListNode *p=head;p!=NULL;p=p->next){
		cout<<p->val<<endl;
	}
	cout<<getVal(l1)<<endl;
//int val=getVal(l1);
//cout<<val<<endl;
	return 1;
}
