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
    TreeNode pre = null;  
      
    public boolean isValidBST(TreeNode root) {  
        // Traverse the tree in inorder.  
        if (root != null) {  
            // Inorder traversal: left first.  
            if (!isValidBST(root.left)) return false;  
              
            // Compare it with the previous value in inorder traversal.  
            if (pre != null && root.val <= pre.val) return false;  
              
            // Update the previous value.  
            pre = root;  
              
            // Inorder traversal: right last.  
            return isValidBST(root.right);  
        }  
        return true;  
     }  
}

自己用的是暴力枚举法。。。。 
这个方法的原理是中序遍历一棵二叉平衡树得到的是递增序列
