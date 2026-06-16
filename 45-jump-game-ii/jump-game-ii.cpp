class Solution {
public:
    int jump(vector<int>& nums) {

        if(nums.size() <= 1)
            return 0;
        vector<int> dp(nums.size(),-1);
        return magic(nums, 0, dp);
    }



private:
    int magic(vector<int>& nums, int i, vector<int>& dp) {

        if(i >= nums.size() - 1)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int mini = INT_MAX;

        for(int j = 1; j <= nums[i]; j++) {

            int child = magic(nums, i + j, dp);

            if(child != INT_MAX)
                mini = min(mini, 1 + child);
        }

        return dp[i] = mini;
    }


};