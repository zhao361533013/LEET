222. Count Complete Tree Nodes

Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int countNodes(TreeNode root) {
        if (root==null){
            return 0;
        }
        int left = countleft(root);
        int right = countright(root);
        if (left == right){
            return (2<<(left-1))-1;
        }
        else {
            return countNodes(root.left)+countNodes(root.right) +1;
        }
    }
    public int countright (TreeNode root){
        int count = 0 ;
        while (root != null){
            count++;
            root = root.right;
        }
        return count;
    }
    public int countleft (TreeNode root){
        int count = 0;
        while (root != null){
            count++;
            root = root.left;
        }
        return count;
    }
}
