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
    public TreeNode trimBST(TreeNode root, int low, int high) {
        return trim(null, root, low, high);
    }
    
    private TreeNode trim(TreeNode prev, TreeNode cur, int low, int high) {
        if(cur==null) {
            return null;
        }
        
        if(cur.val>=low && cur.val<=high) {
            if(prev==null) {
                prev = cur;
            }
            else if(prev.val > cur.val ) {
                prev.left = cur;
            } else {
                prev.right = cur;
            }
            
            TreeNode left = cur.left;
            TreeNode right = cur.right;
            cur.left = null;
            cur.right = null;
            
            trim(cur, right, low, high);
            trim(cur, left, low, high);
            
            return prev;
        } else if(cur.val<low) {
            return trim(prev, cur.right, low, high);
        } else {
            return trim(prev, cur.left, low, high);
        }
    }
}
