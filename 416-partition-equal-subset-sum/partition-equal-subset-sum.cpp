class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = sum(nums,0,nums.size()-1);
        if(s%2!=0) return false;
        vector<vector<int>> dp(nums.size(),vector<int>((s/2)+1,-1));
        return magic(nums,0,s/2,dp);
    }
private:
    bool magic(vector<int>& nums, int i,int sum,vector<vector<int>>& dp){

        if(sum==0) return true;
        if(i==nums.size()) return false;

        if(dp[i][sum] != -1) return dp[i][sum];

        bool taken = false;
        if(nums[i]<=sum){
            taken = magic(nums,i+1,sum-nums[i],dp);
        }

        bool notTaken = magic(nums,i+1,sum,dp);

        return dp[i][sum]= taken || notTaken;
    }

    int sum(vector<int> nums,int start, int last){
        int ans=0;

        for(int i=start; i<=last; i++){
            ans+= nums[i];
        }

        return ans;
    }
    
};