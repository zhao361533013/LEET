129. Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.






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
    public int sumNumbers(TreeNode root) {
        if (root == null){
            return 0;
        }
        int m = 0;
        List <Integer> a = new ArrayList<Integer>();
        L (root,0,a);
        for (int i = 0; i<= a.size()-1;i++){
            m += a.get(i);
        }
        return m;
    }
    public void L (TreeNode root, int temp,  List <Integer> Array){
            temp = root.val+ temp*10;
        if (root.right==null&&root.left == null){
            Array.add(temp);
        }
        if (root.left!= null){
            L (root.left, temp, Array);
        }
        if (root.right != null){
            L (root.right, temp, Array);
        }
        temp = (temp-root.val)/10;
    } 
}

/*** 用到了昨天学的回溯算法，一个最终解集合，一个临时解，关于回溯算法的讲解： http://blog.csdn.net/versencoder/article/details/52071930 
