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
    public int maxDepth(TreeNode root) {
        if (root == null)
        {
            return 0;
        }
        int k = 0;
        k = java.lang.Math.max(maxDepth(root.right),maxDepth(root.left)) +1 ;
        return k;
    }
    
}
