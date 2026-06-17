class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        vector<int> dp(nums.size(),-1);

        dp[nums.size()-1] = 0;
        return magic(nums,0,dp);
    }

private:
    int magic(vector<int>& nums,int i, vector<int>& dp){
        if(i>nums.size()-1) return dp[i];

        if(nums[i]==0 && i!=nums.size()-1) return INT_MAX;

        if(dp[i] != -1) return dp[i];

        int jumps = nums[i];
        int mini = INT_MAX;

        for(int j=1; j<=jumps && i+j<nums.size(); j++){
            int res = magic(nums,i+j,dp);
            
            if(res !=INT_MAX)
                mini = min(mini,1+res);
        }
        return dp[i] = mini;
    }
};