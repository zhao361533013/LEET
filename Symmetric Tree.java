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
    public boolean isSymmetric(TreeNode root) {
       if (root==null)
       {
           return true;
       }
        return isSameTree(root.right,root.left);
    }
    public boolean isSameTree(TreeNode p, TreeNode q) {
       if(p==null&&q==null)
        {
          return true;
        }
        if (p==null||q==null)
        {
            return  false;
        }
        if (p.val==q.val)
        {
            return isSameTree(p.left,q.right)&&isSameTree(p.right,q.left);
        }
            else return false;
      
    }
}
