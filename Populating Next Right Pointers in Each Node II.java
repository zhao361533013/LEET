117. Populating Next Right Pointers in Each Node II

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL





/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root!=null){
            TreeLinkNode temp = root.next;  
             while (root.next!= null&&root.next.right == null&& root.next.left ==null){
                            root.next = root.next.next;
                        }
            if (root.left!=null&&root.right!=null){
                root.left.next = root.right;
            }
            if (root.right!=null){   
                if (root.next !=null){
                    if (root.next.left!=null){
                        root.right.next = root.next.left;
                    }
                    if (root.next.left==null&&root.next.right!=null){
                        root.right.next = root.next.right;
                    }
                }
            }
            if (root.left != null && root.right==null){ 
                if (root.next !=null){
                    if (root.next.left!=null){
                        root.left.next = root.next.left;
                    }
                    if (root.next.left==null&&root.next.right!=null){
                        root.left.next = root.next.right;
                    }
                }
            }
            root.next = temp;
            connect(root.right);
            connect(root.left);
        }
      
    }
}
