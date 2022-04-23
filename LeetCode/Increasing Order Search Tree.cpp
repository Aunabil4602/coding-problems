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
    public TreeNode increasingBST(TreeNode root) {
        return call(root, null);
    }
    
    public TreeNode call(TreeNode root, TreeNode rightTree) {
        if(root==null) return rightTree;
        
        root.right = call(root.right, rightTree);
        TreeNode left = root.left;
        root.left = null;
        return call(left, root);
    }
}
