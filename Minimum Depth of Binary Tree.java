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
    public int minDepth(TreeNode root) {
        if (root == null)
        {
            return 0;
        }
        int k =1;
        if (root.left==null&&root.right!=null)
        {
            k = minDepth(root.right)+1;
        }
         if (root.left!=null&&root.right==null)
         {
            k = minDepth(root.left)+1;
         }
        if (root.left!=null&&root.right!=null)
        {
            k = java.lang.Math.min(minDepth(root.left),minDepth(root.right))+1;
        }
        return k;
    }
}
