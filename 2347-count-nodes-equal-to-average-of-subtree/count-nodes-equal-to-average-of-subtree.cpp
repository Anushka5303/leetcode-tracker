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
    int ans = 0;
    int averageOfSubtree(TreeNode* root) {
        magic(root);
        return ans;
    }
private:
    pair<int,int> magic(TreeNode* root){

        if(root == NULL) return {0,0};

       pair<int,int> lefty = magic(root->left);
       pair<int,int> righty = magic(root->right);

       int sum = lefty.first + righty.first + root->val;
       int count = lefty.second + righty.second + 1;

       int avg = sum/count;

       if(root->val == avg)
       ans++;

       return {sum,count};
    }
};