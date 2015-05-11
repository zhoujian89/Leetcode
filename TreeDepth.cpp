#include<queue>
#include<stdio.h> 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    int maxDepth(TreeNode *root) {
        int depth=0;
        int left_flag=0,right_flag=0;
        const TreeNode *p;
        std::queue <const TreeNode*> q;
        if(root!=NULL){
            q.push(root);
            depth++;
        }
        while(!q.empty()){
            p=q.front();
            q.pop();
            if(p->left!=NULL){
                q.push(p->left);
                left_flag=1;
                
            }
            if(p->right!=NULL){
                q.push(p->right);
                right_flag=1;
            }
            
            if(left_flag==1 || right_flag==1) depth++;
            
        }
        return depth;
        
    }
};
int main(){
	return 0;
}
