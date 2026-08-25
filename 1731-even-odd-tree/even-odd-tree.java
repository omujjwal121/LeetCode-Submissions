/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode>q = new LinkedList<>();
        int level = 0;
        q.offer(root);
        while(q.size()>0)
        {
            Queue<TreeNode> temp = new LinkedList<>();
            int lastval = 0;
            if(level%2==1) lastval = 1000001;
            while(q.size()>0)
            {
                TreeNode curr = q.peek(); q.poll();
                if(level%2==0 && (curr.val<=lastval || curr.val%2==0) ) return false;
                else if(level%2==1 && (curr.val>=lastval || curr.val%2==1)) return false;
                lastval = curr.val;
                if(curr.left!=null) temp.offer(curr.left);
                if(curr.right!=null) temp.offer(curr.right);
            }
            q = temp;
            level++;
        }
        return true;
    }
}