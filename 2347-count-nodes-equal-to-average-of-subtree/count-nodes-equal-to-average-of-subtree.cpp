
class Solution {
public:
    int count=0;
    void solve( TreeNode* root, int &sum, int &nodes){
        if(root==NULL) return;
        int prevsum= sum;
        int prevnodes=nodes;
        sum+=root->val;
        nodes+=1;
        if(root->left){
            solve(root->left, sum,nodes);
        }
        if(root->right){
            solve(root->right, sum, nodes);
        }

        int subtreesum = sum - prevsum;
        int subtreenode= nodes - prevnodes;
        if(subtreesum / subtreenode == root->val) count++;
    }
    int averageOfSubtree(TreeNode* root) {
        int sum=0;
        int nodes=0;
        solve(root,sum,nodes);
        return count;
    }
};