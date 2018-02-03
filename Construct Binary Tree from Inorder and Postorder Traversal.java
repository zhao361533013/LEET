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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int a = inorder.length;
        int b = postorder.length;
        return L(inorder,postorder,0,a-1,0,b-1);
    }
    public TreeNode L(int[] order, int[] postorder,int ostart,int oend, int pstart, int pend)
    {
        if (oend < ostart || pstart > pend)
        {
            return null;
        }
        int root = postorder[pend];
        TreeNode m = new TreeNode(root);
        int q = 0;
        for (int i = ostart;i<=oend;i++)
        {
            if (root == order[i])
            {
                q = i;
                break;
            }
        }
        int len = q - ostart;
        m.left = L(order,postorder,ostart,q-1,pstart,pstart+len-1);
        m.right = L (order,postorder,q+1,oend,pstart+len,pend-1);
        return m;
    }
}

/*** 给出后序遍历和中序遍历 求出这个树的结构
* 思路就是通过后序遍历的最后一个节点确定根节点 然后在中序遍历中找到这个节点 则中序遍历中此节点前面的就是左子树，后面的就是右子树。对
*左右子树递归调用这个函数。
