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
    long long total(TreeNode* root)
    {
        if(root == NULL) return 0;
        long long l = total(root-> left);
        long long r = total(root-> right);

        return root->val+l+r;
    }
    long long pro(TreeNode* root, long long& total, long long& maxi)
    {
        if(root == NULL) return 0;
        long long l = pro(root->left, total, maxi);
        long long r = pro(root->right, total, maxi);
        maxi = max(maxi, (root->val+l+r) * (total - root->val -l -r));
        return root->val+l+r;
    }
    int maxProduct(TreeNode* root) {
        long long totall = total(root);
        long long maxi = 0;
        pro(root, totall, maxi);
        return maxi%(long(1e9+7));
    }
};