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
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        levelrecursion(root,result,0);
        return result;
    }
    public static void levelrecursion(TreeNode root,List<List<Integer>> result,int level)
    {
        if (root ==null)
        {
            return;
        }
        if (result.size()< level+1)
        {
            result.add(new ArrayList<Integer>());
        }
        result.get(level).add(root.val);
        levelrecursion(root.left,result,level+1);
        levelrecursion(root.right,result,level+1);       
    }
}

/// 树的层序遍历 并按层输出
