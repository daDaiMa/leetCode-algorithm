/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans=NULL;
        dfs(root,p,q); 
        return ans;
    }
    
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)return 0;
        int left=dfs(root->left,p,q);
        int right=dfs(root->right,p,q);
        int mid=(root==q||root==p)?1:0;
        if(left+right+mid>=2&&!ans)
            ans=root;
        return left+right+mid;
    }
};
