/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int maxDepth = -1;
    private int sum = 0;
    
    public int deepestLeavesSum(TreeNode root) {
        dfs(root, 0);
        return this.sum;
    }
    
    private void dfs(TreeNode node, int depth) {
        if(node==null) {
            return;
        }
        
        if(depth>this.maxDepth) {
            this.maxDepth = depth;
            this.sum = 0;
        }
        
        if(depth == maxDepth) {
            this.sum+=node.val;
        }
        
        dfs(node.left, depth+1);
        dfs(node.right, depth+1);
    }
}
