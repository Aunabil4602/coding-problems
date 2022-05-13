/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if(root==null) {
            return null;
        }
        
        if(root.left!=null){
            root.left.next = findNext(root, root.left);
        }
        
        if(root.right!=null) {
            root.right.next = findNext(root.next, root.right);
        }
        
        connect(root.right);
        connect(root.left);
        
        
        return root;
    }
    
    private Node findNext(Node cur, Node source) {
        if(cur==null) {
            return null;
        }
        
        if(cur.left!=null && cur.left!=source) {
            return cur.left;
        }
        
        if(cur.right!=null && cur.right!=source) {
            return cur.right;
        }
        
        return findNext(cur.next, source);
    }
}
