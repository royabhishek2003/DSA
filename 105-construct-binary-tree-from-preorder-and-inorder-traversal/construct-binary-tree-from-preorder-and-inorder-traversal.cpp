
class Solution {
public:
    int i=0;
    int n;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int st, int end){

        if(st<0 || end>n || st>end || i>=n) return NULL;
        int ele=preorder[i];
        TreeNode* root= new TreeNode(ele);
        i++;
        int idx=0;
        while(inorder[idx]!=ele){
            idx++;
        }
        // idx++;
        root->left= solve(preorder,inorder,st,idx-1);
        root->right= solve(preorder, inorder,idx+1,end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n=preorder.size();
        return solve(preorder,inorder,0,n-1);
     
    }
};