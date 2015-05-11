#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
struct node  
{ int val;
  int list;
};
//比较函数
bool cmp(node  a,node  b) 
{
    return a.val>b.val;
}
int main()
{
	vector<list<node> > v;
	list<node> l1;
	list<node> l2;
	list<node> l3;
	list<node> l4;
	vector<node> heap;
	vector<int> ans;
	//构造需要合并的数据  
    for(int value = 1; value <=20; value++)  
    {  
        int r = rand() % 4; 
        node *a = new node;  
        a->list = r;  
        a->val = value;
		if(r==0){
		l1.push_back(*a);	
		}  
		else if(r==1){
		l2.push_back(*a);	
		}
		else if(r==2){
		l3.push_back(*a);
		}
		else {
		l4.push_back(*a);	
		}	
    }  
    v.push_back(l1);
    v.push_back(l2);
    v.push_back(l3);
    v.push_back(l4);
    for(int i=0;i<v.size();i++){
		for(list<node>::iterator iter=v[i].begin();iter!=v[i].end();iter++)
		cout<<(*iter).val<<"  ";//<<(*iter).list<<" "
		cout<<endl;
	}
	cout<<endl;
	int k=v.size();
	for(int i=0;i<k;i++){
		cout<<"size: "<<v[i].size()<<" "; 
		if(v[i].size()>0){
			heap.push_back(v[i].front());
			v[i].pop_front();
		}
	}
	cout<<endl; 
	//step1：取每个链表的第一个元素，构造成一个含有k个元素的堆
	make_heap(heap.begin(),heap.end(),cmp);
	cout<<"............"<<endl;
	for(int i=0;i<heap.size();i++){
		cout<<heap[i].val<<" ";
	}
	cout<<endl;
    while(1){
    	//得到堆中第一个元素所在的list编号 
    	//step2：把根结点的值记入排序结果中  
		int r=heap[0].list;
		ans.push_back(heap[0].val);
		//step3：判断根结点所在的链表，若该链表为空，则堆的大小要调整减1 
		if(v[r].size()==0){
			 //删除根结点，调整堆,堆由k个元素变为k-1个元素，只有k-1个元素在比较，去掉堆顶元素 
			 pop_heap(heap.begin(),heap.end(),cmp);
			 heap.pop_back();
			 if(heap.size()==0) break;
		}
		else//若该链表不为空  
        { //把根结点替换为原根结点所在链表中的第一个元素 
			heap.push_back(v[r].front()); 
			v[r].pop_front();
            pop_heap(heap.begin(),heap.end(),cmp);
			heap.pop_back();  
        } 
	//for(int i=0;i<heap.size();i++){
	//cout<<heap[i].val<<" ";
	//} 
	//cout<<endl;
       
    }
	for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<endl;
	for(int i=0;i<heap.size();i++){
	cout<<heap[i].val<<" ";
	}
	return 1;
}
