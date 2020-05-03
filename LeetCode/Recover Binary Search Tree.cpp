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
 
 // Solution Idea from geeksforgeeks https://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/
 
class Solution { 
public:
    vector<TreeNode* > dp;
    void recoverTree(TreeNode* root) {
        dp.clear();
        order(root);
        
        int cnt=0;
        for(int i=0;i<dp.size()-1;i++){
            if(dp[i]->val > dp[i+1]->val)cnt++;
        }
        
        if(cnt==1){
            for(int i=0;i<dp.size()-1;i++){
                if(dp[i]->val > dp[i+1]->val)swap(dp[i]->val,dp[i+1]->val);
            }
        }
        if(cnt==2){
            vector<TreeNode*> ok(2);
            int ck=0;
            for(int i=0;i<dp.size()-1;i++){
                if(dp[i]->val > dp[i+1]->val)ok[ck]=dp[i+ck],ck++;
            }
            swap(ok[0]->val,ok[1]->val);
        }
    }
    
    void order(TreeNode* root){
        if(root==NULL)return;
        order(root->left);
        dp.push_back(root);
        order(root->right);
    }
   
};
