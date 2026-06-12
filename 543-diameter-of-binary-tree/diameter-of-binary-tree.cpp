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
    int diameterOfBinaryTree(TreeNode* root) {

        int ans = INT_MIN;

        magic(root, ans);

        return ans;
        
    }
private:
    int magic(TreeNode* root, int& ans)
    {
        if(root == NULL) return 0;

        int l = magic(root->left, ans);
        int r = magic(root->right, ans);

        ans = max(ans,l+r);

        return 1+max(l,r);
    }
};