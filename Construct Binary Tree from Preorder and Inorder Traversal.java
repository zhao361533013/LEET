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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int a = preorder.length;
        int b = inorder.length;
        if (preorder == null || inorder == null || preorder.length == 0 || preorder.length != inorder.length) {
             return null;
        }
        return L(preorder,inorder,0,a-1,0,b-1);
    }
    public TreeNode L(int[] preorder,int[] inorder,int pfirst,int plast,int ifirst,int ilast){
        
        if (pfirst >plast||ifirst>ilast){
            return null;
        }
        int f = preorder[pfirst];
        TreeNode m = new TreeNode(f);
        int q = 0;
        for (int i = ifirst;i<=ilast;i++)
        {
            if (f == inorder[i])
            {
                q = i;
                break;
            }
        }
        int len = q - ifirst;
        m.left = L(preorder,inorder,pfirst+1,pfirst+len,ifirst,q-1);
        m.right = L(preorder,inorder,pfirst+len+1,plast,q+1,ilast);
        return m;
    }
}
