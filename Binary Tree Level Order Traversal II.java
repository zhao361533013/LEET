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
   
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        L (root,result,0);
        Collections.reverse(result);
        return  result;
    }
    public List<List<Integer>> L(TreeNode root, List<List<Integer>> n,int level){
          if (root == null)
          {
              return null;
          }
        int s = n.size();
        if (level +1 > s)
        {
            List<Integer> re = new ArrayList<>();
            re.add(root.val);
            n.add(re);
        }
        if (level + 1 <= s )
        {
            n.get(level).add(root.val);
        }
        L(root.left,n,level+1);
        L(root.right,n,level+1);
        return n;
    }
}
