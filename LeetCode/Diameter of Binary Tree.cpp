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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans=dp(root);
        return max(max(ans.first,ans.second)-1,0);
    }
    
    pair<int,int> dp(TreeNode* node){
        if(node==NULL)return {0,0};
        pair<int,int> left=dp(node->left);
        pair<int,int> right=dp(node->right);
        
        return {1+max(left.first,right.first),max({left.second,right.second,1+(left.first+right.first)})};
    }
};
