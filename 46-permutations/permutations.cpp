class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int i=0;
        vector<int> ds;
        vector<vector<int>> ans;

        magic(nums,i,ds,ans);

        return ans;
    }
private: 
    void magic(vector<int>& nums, int i, vector<int>& ds, vector<vector<int>>& ans)
    {   
        
        if(i>=nums.size())
        {   
            ans.push_back(nums);
            return;
        }

        for(int j=i; j<nums.size(); j++)
        {
            swap(nums[i],nums[j]);
            magic(nums,i+1,ds,ans);
            
            swap(nums[i],nums[j]);
        }
    }
};