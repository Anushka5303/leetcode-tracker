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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return magic(p,q);
    }
private:
    bool magic(TreeNode* p, TreeNode* q)
    {
        if(p==NULL || q==NULL)
        {
            return p==q;
        }

        return (p->val == q->val) &&
        magic(p->left, q->left) &&
        magic(p->right, q->right);
    }
};