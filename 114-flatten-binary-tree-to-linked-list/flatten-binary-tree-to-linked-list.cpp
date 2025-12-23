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
    void linked(TreeNode* root, vector<TreeNode*>& v)
    {
        if(root  == NULL) return;
        v.push_back(root);
        linked(root->left, v);
        linked(root->right, v);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> v;

        linked(root, v);
        int k = v.size();
        for(int i=0;i<k-1;i++)
        {
            v[i]->left = NULL;
            v[i]->right = v[i+1];
        }
        if(v.size())
        {
            v.back()->left = NULL;
            v.back()->left = NULL;
        }
    }
};