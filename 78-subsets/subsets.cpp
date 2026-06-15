class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        vector<int> ds;
        vector<vector<int>> ans;

        magic(nums,i,ds,ans);

        return ans;
    }
private:
    void magic(vector<int>& nums, int i, vector<int> ds, vector<vector<int>>& ans)
    {
        if(i>=nums.size())
        {
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        magic(nums,i+1,ds,ans);

        ds.pop_back();
        magic(nums,i+1,ds,ans);
    }
};