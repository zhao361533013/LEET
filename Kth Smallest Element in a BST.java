230. Kth Smallest Element in a BST


Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?



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
    int seq = 0;
        int res = 0;
    public int kthSmallest(TreeNode root, int k) {
        seq = k-1;
        
        kthSmallest(root);
        return  res;
    }
    public void kthSmallest(TreeNode root) {
        if (root == null|| seq<0)
        {
            return;
        }
        
        kthSmallest(root.left);
        if (seq == 0)
        {
            res = root.val;
            seq--;
        }
        
        seq--;
        kthSmallest(root.right);        
        
    }    
}


class Solution {
     Stack <TreeNode>p = new Stack<TreeNode>(); 
    public int kthSmallest(TreeNode root, int k) {
        int n = 0;
        while (root != null){
            p.push (root);
            root = root.left;
        }
        for (int i = 1; i <=k ; i++){
            TreeNode temp = p.pop();
            n = temp.val;
            temp = temp.right;
            while (temp != null){
                p.push (temp);
                temp = temp.left;
            }
        }
        return n;
    }


}
