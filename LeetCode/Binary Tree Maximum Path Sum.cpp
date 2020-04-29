/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int MN;
    int maxPathSum(TreeNode* root) {
        MN=INT_MIN/2;
        auto ans=dfs(root);
        return max(ans.first,ans.second);
    }
    
    pair<int,int> dfs(TreeNode* x){
        if(x==NULL)return {MN,MN};
        auto left=dfs(x->left);
        auto right=dfs(x->right);
        int one=x->val+max({left.first,right.first,0});
        int two=x->val+max(left.first,0)+max(right.first,0);
        two=max({two,left.second,right.second,left.first,right.first});
        return {one,two};
    }
};
