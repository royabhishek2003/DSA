
class Solution {
public:
    int count=0;
    void findsum_node(TreeNode* root, int &sum, int &node){
       
       if(root==NULL){
          return;
       }
       sum+=root->val;
       node+=1;
       if(root->left){
        findsum_node(root->left, sum, node);
       }
       if(root->right){
        findsum_node(root->right, sum, node);
       }
    
    }
    void solve( TreeNode* root){
        if(root==NULL) return;
        int sum=0;
        int nodes=0;
        findsum_node(root, sum,nodes);
        if(sum/nodes  ==  root->val) count++;
        solve(root->left);
        solve(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return count;
    }
};