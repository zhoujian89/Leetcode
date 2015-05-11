#include<iostream>
#include<vector>
using namespace std;
struct Node{
	int key;
	struct Node *left,*right;
};

Node * newNode(int key){
	Node * temp=new Node;
	temp->key=key;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}
Node * findLCA(Node * root,int n1,int n2){
	if(root==NULL) return NULL;
	// ֻҪn1 �� n2 ����һ��ƥ�伴��
    //  (ע�⣺��� һ���ڵ�����һ�����ȣ��򷵻ص������Ƚڵ㡣��Ϊ�ݹ���Ҫ���ص�����)
	if(root->key==n1 ||root->key==n2) return root;
	// �ֱ���������������
	Node * LeftNode=findLCA(root->left,n1,n2);
	Node * RightNode=findLCA(root->right,n1,n2);
	// ��������طǿ�ָ�� Non-NULL, ��˵�������ڵ�ֱ�����������������У���ǰ�ڵ�϶�ΪLCA
	if(LeftNode&&RightNode) return root;
	// ���һ��Ϊ�գ���˵��LCA����һ������
	else if(LeftNode&&!RightNode) return LeftNode;
	else if(!LeftNode&&RightNode) return RightNode;
	else return NULL;
}

Node * GetLastCommonParent(Node *root,int n1,int n2){
	Node * pre=NULL, * cur=NULL;
    vector<Node *> v;
    vector<Node *> v1;
    if(root!=NULL) v.push_back(root);
    while(!v.empty()){
    	cur=v[v.size()-1];
        if(((cur->left==NULL)&&(cur->right==NULL))||
        ((pre!=NULL)&&(cur->right==pre||cur->left==pre))){
        	pre=cur;
        	v.pop_back();
        	if(pre->key==n1){
        		for(int i=0;i<v.size();i++) v1.push_back(v[i]);
        		for(int j=0;j<v1.size();j++) {
        			cout<<"v1: "<<v1[j]->key<<"  ";
        		}
        		cout<<endl;
        	}
        	if(pre->key==n2){
        		for(int i=0;i<v.size();i++) {
        			cout<<"v: "<<v[i]->key<<"  ";
        		}
        		cout<<endl;
        			for(int i=v.size()-1;i>=0;i--){
        			Node * temp=v[i];
        			for(int j=v1.size()-1;j>=0;j--){
        			if(temp->key==v1[j]->key) {
        				return temp;
        			}
        		}
        	}
        }
    }
    else{//����ýڵ㲻�ܷ��ʣ���������ջ
            if(cur->right!=NULL) v.push_back(cur->right);
            if(cur->left!=NULL) v.push_back(cur->left);
            }   
        }
		return NULL;	
}
int main(){
	// ��������ͼ�е���
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key;
    cout<<endl;
    cout<<"............"<<endl;
 //   cout << "LCA(4, 5) = " << GetLastCommonParent(root,4,5)->key;
  //  cout << "\nLCA(4, 6) = " << GetLastCommonParent(root, 4, 6)->key;
    //cout << "\nLCA(3, 4) = " << GetLastCommonParent(root, 3, 4)->key;
  //  cout << "\nLCA(2, 4) = " << GetLastCommonParent(root, 2, 4)->key;
	return 1;
}

