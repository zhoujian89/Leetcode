#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
//
 //* Definition for singly-linked list.
  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

 
class Solution {
public:
    //±È½Ïº¯Êý
     struct Node  
    {  
        ListNode* pNode;  
        int index;  
        Node(ListNode* _pNode = NULL, int _index = 0):pNode(_pNode), index(_index){};  
    } ;
 
   //bool cmp(Node  a,Node  b) 
  // {
  //  return a.pNode->val > b.pNode->val;
  // }
   class comp {  
   public:  
    bool operator() (Node  a,Node  b) const {  
        return  a.pNode->val > b.pNode->val;  
    }  
};
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode dummy(-1);  
        ListNode* prev = &dummy; 
        vector<Node> heap;
        for(int i=0;i<lists.size();i++){
            heap.push_back(Node(lists[i],i));
            lists[i]=lists[i]->next;
        }
        make_heap(heap.begin(),heap.end(),comp());
        while(1){
            int r=heap[0].index;
            prev->next=heap[0].pNode;
            prev=prev->next;
            	if(lists[r]==NULL){
            	    pop_heap(heap.begin(),heap.end(),comp());
			        heap.pop_back();
            	    if(heap.size()==0) break;
            	}
            	else{
                    heap.push_back(Node(lists[r],r)); 
			        lists[r]=lists[r]->next;
                    pop_heap(heap.begin(),heap.end(),comp());
			        heap.pop_back();
            	}
        }
        prev->next = NULL;  
        return dummy.next;  
    }
};
int main(){
	vector<int > v;
	for(int i=0;i<5;i++) v.push_back(i);
	cout<<v.size()<<endl;
	for(vector<int >::iterator iter=v.begin();iter!=v.end();iter++){
		if(*iter==3) v.erase(iter);
		if(*iter==1) v.erase(iter);
	}
	cout<<v.size()<<endl;
	vector<ListNode *> lists;
	lists.push_back(NULL);
	lists.push_back(NULL);
	lists.push_back(NULL);
	cout<<lists.size()<<endl;
	for(vector<ListNode *>::iterator iter=lists.begin();iter!=lists.end();iter++){
           if(*iter==NULL) {
           cout<<"  dddddddddddddd"<<endl;
           lists.erase(iter);
           }
           if(iter==lists.end()-1) break;
        }
  // for(int i=0;i<lists.size();i++){
  // 	if(lists[i]==NULL) 
  // }
	return 1;
} 
