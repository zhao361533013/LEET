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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> a = new ArrayList<List<Integer>>();
        List<Integer> temp = new ArrayList<Integer>();
        if (root == null){
            return a;
        }
        L (root,sum,a,temp);
        return a;
    }
    public void L (TreeNode root,int sum, List<List<Integer>> a,List<Integer> temp)
    {
        temp.add(root.val);
        sum -= root.val;
        if (root.left==null&&root.right == null){
            if (sum == 0){
                a.add(new ArrayList<>(temp));
            }
        }     
        if (root.left!=null){
             L (root.left,sum,a,temp);
        }
        if (root.right!=null ){
             L (root.right,sum,a,temp);
        }
        temp.remove(temp.size()-1);
    }
}
