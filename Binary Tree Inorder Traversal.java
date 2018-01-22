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
    public List<Integer> list = new ArrayList<Integer>();
    public List<Integer> inorderTraversal(TreeNode root) {
        inorder (root);
        return list;
    }
    public void inorder (TreeNode root)
    {
        if (root==null)
        {
            return;
        }
        if(root.left != null)
        {
            inorder (root.left);
        }
        list.add(root.val);
          if(root.right!=null)
        {
            inorder (root.right);
        }
    }
}
