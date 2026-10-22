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
    int ans = 0;
    record pair(int sum, int cnt) {}
    private pair check(TreeNode root)
    {
        if(root == null) return new pair(0,0);
        int val = root.val;
        pair left = check(root.left);
        pair right = check(root.right);
        if(val == (val+left.sum+right.sum)/(left.cnt+right.cnt+1)) ans++;
        return new pair(left.sum+right.sum+val, left.cnt+right.cnt+1);
    }
    public int averageOfSubtree(TreeNode root) {
        check(root);
        return ans;
    }
}