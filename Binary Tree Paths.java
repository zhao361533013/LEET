257. Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]


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
    public List<String> resultList = new ArrayList<String>();
     public List<String> binaryTreePaths(TreeNode root) {
        if (root == null) {
            return resultList;
        }
        List<String> singleResult = new ArrayList<>();

        getTreePath(root, singleResult);
        return resultList;
    }
    private void getTreePath(TreeNode node, List<String> singleResult) {
        singleResult.add(node.val + "");
        if (node.left == null && node.right == null) {
            String a = path(singleResult);
            resultList.add(a);
        }
        if (node.left != null) {
            getTreePath(node.left, new ArrayList<>(singleResult));
        }
        if (node.right != null) {
            getTreePath(node.right, new ArrayList<>(singleResult));
        }
    }
    private String path(List<String> singleResult){
        String a = "";
        if (singleResult.size() == 1){
            return singleResult.get(0);
        }
        for (int i = 0 ; i < singleResult.size()-1;i++){
            a = a + singleResult.get(i) +"->"; 
        }
        a = a + singleResult.get(singleResult.size()-1);
        return a;
    }
}
/***深度优先搜索 DFS  借鉴：http://blog.csdn.net/crazy1235/article/details/51474128（这个人用了6种方法！！）
