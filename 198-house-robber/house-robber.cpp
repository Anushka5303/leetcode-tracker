class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        dp[n-1] = nums[n-1];
        // dp[n-2] = nums[n-2];

        
        
        // return magic(nums,0,ans,dp);
        // return ans;
        for(int i=n-2; i>=0; i--){
            int take = nums[i];
            if(i+2<n) take += dp[i+2];
            
            int notTake = 0 + dp[i+1];

            int ans = max(take,notTake);

            dp[i] = ans;
        }
        return dp[0];
       
    }
// private:
// int magic(vector<int>& nums,int i,int& ans,vector<int>& dp){
//     if(i==nums.size()-1) return dp[i];

//     if(dp[i] != -1) return dp[i];

//     int take = INT_MIN, notTake = INT_MIN;

//     if(i+2<nums.size()) take = magic(nums,i+2,ans,dp);

//     if(take != INT_MIN){
//         take += nums[i];
//     }else{
//         take = nums[i];
//     }


//     if(i+1<nums.size()) notTake = magic(nums,i+1,ans,dp);

//     int maxi = max(take,notTake);

//     ans=max(ans,maxi);

//     return dp[i] = maxi;
// }
};