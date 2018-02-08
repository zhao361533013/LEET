199. Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].



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
    public List<Integer> rightSideView(TreeNode root) {
        ArrayList <ArrayList <Integer>> L1 = new ArrayList <ArrayList <Integer>>();
        ArrayList <Integer> L2 = new ArrayList <Integer>();
        if (root ==null){
            return L2;
        }
        L (L1,root,0);
        for (int i = 0; i <= L1.size()-1;i++)
        {
            int s = L1.get(i).size()-1;
            int q = L1.get(i).get(s);
            L2.add(q);
        }
        return L2;
    }
    public void L(ArrayList <ArrayList <Integer>> L1,TreeNode root, int size){
        if (root == null) return ;
        int a = root.val;
        if (size < L1.size()){
            L1.get(size).add(a);
        }
        if (size == L1.size() ){
            ArrayList <Integer>n = new ArrayList<Integer>();
            n.add(a);
            L1.add(n);
        }
        L (L1,root.left,size+1);
        L (L1,root.right,size+1);
    }
}

思路就是先层序遍历 然后再取每个list的最后一位。
