#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
struct node  
{ int val;
  int list;
};
//�ȽϺ���
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
	//������Ҫ�ϲ�������  
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
	//step1��ȡÿ������ĵ�һ��Ԫ�أ������һ������k��Ԫ�صĶ�
	make_heap(heap.begin(),heap.end(),cmp);
	cout<<"............"<<endl;
	for(int i=0;i<heap.size();i++){
		cout<<heap[i].val<<" ";
	}
	cout<<endl;
    while(1){
    	//�õ����е�һ��Ԫ�����ڵ�list��� 
    	//step2���Ѹ�����ֵ������������  
		int r=heap[0].list;
		ans.push_back(heap[0].val);
		//step3���жϸ�������ڵ�������������Ϊ�գ���ѵĴ�СҪ������1 
		if(v[r].size()==0){
			 //ɾ������㣬������,����k��Ԫ�ر�Ϊk-1��Ԫ�أ�ֻ��k-1��Ԫ���ڱȽϣ�ȥ���Ѷ�Ԫ�� 
			 pop_heap(heap.begin(),heap.end(),cmp);
			 heap.pop_back();
			 if(heap.size()==0) break;
		}
		else//��������Ϊ��  
        { //�Ѹ�����滻Ϊԭ��������������еĵ�һ��Ԫ�� 
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
