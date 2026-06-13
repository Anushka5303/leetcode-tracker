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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        int flag = 1;

        vector<vector<int>> ans;

        if(root==NULL) return ans;

        queue<TreeNode*> d;
        d.push(root);

        while(!d.empty())
        {
            

            int n= d.size();
            int i = n-1;
            vector<int> in(n);

            if(flag==0){
                flag=1;
                while(i>=0)
                {
                    TreeNode* a = d.front();
                    d.pop();

                    if(a->left) d.push(a->left);
                    if(a->right) d.push(a->right);

                    in[i] = a->val;
                    i--;
                }
                ans.push_back(in);
            }else{
                flag=0;
                while(i>=0)
                {
                    TreeNode* a = d.front();
                    d.pop();

                    if(a->left) d.push(a->left);
                    if(a->right) d.push(a->right);

                    in[n-i-1] = a->val;
                    i--;
                }
                ans.push_back(in);
            }
        }
        return ans;
        
        
    }
};