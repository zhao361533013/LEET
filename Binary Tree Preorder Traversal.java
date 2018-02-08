144. Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

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
    public List<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> L = new ArrayList<Integer>();
        Li(root,L);
        return L;
    }
    public void Li(TreeNode root, ArrayList<Integer> a){
        if (root!=null){
        a.add(root.val);
        Li(root.left,a);
        Li(root.right,a);
        }
    }
}
/*** 只会一个递归的解法，然而是trivial.....

下面这个方法是不用迭代的方法。
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
    public List<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        if (root == null){
            return list;
        }
        Stack<TreeNode> p = new Stack<TreeNode>();
        p.push(root);
        TreeNode temp = null;
        while (!p.isEmpty()){
            temp = p.pop();
            list.add(temp.val);
            if (temp.right != null){
                p.push(temp.right);
            }
            if (temp.left != null){
                p.push(temp.left);
            }
        }
        return list;
    }
}

