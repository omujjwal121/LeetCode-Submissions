/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void count(TreeNode* root, long long &ans,long long sum, long long& target)
    {
        if(root == NULL) return;
        if(sum ==   target) ans++;
        if(root->left) count(root->left, ans, sum+root->left->val, target);
        if(root->right) count(root->right, ans, sum+root->right->val, target);
    }
    void solve(TreeNode* root, long long& target, long long& ans)
    {
        if(root == NULL) return;
        long long sum = 0;long long summ = root->val;
        count(root, sum, summ, target);
        ans+=sum;
        if(root->left) solve(root->left, target, ans);
        if(root->right) solve(root->right, target, ans);
    }
    int pathSum(TreeNode* root, int target) {
        long long ans = 0;
        long long targett = target;
        solve(root, targett, ans);
        return ans;
    }
};