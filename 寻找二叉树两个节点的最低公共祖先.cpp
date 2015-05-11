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
	// 只要n1 或 n2 的任一个匹配即可
    //  (注意：如果 一个节点是另一个祖先，则返回的是祖先节点。因为递归是要返回到祖先)
	if(root->key==n1 ||root->key==n2) return root;
	// 分别在左右子树查找
	Node * LeftNode=findLCA(root->left,n1,n2);
	Node * RightNode=findLCA(root->right,n1,n2);
	// 如果都返回非空指针 Non-NULL, 则说明两个节点分别出现了在两个子树中，则当前节点肯定为LCA
	if(LeftNode&&RightNode) return root;
	// 如果一个为空，在说明LCA在另一个子树
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
    else{//如果该节点不能访问，则让其入栈
            if(cur->right!=NULL) v.push_back(cur->right);
            if(cur->left!=NULL) v.push_back(cur->left);
            }   
        }
		return NULL;	
}
int main(){
	// 构造上面图中的树
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

