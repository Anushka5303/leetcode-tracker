class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[0] = 1;

        for(int i=2; i<=n; i++){
            int one = dp[i-1];
            int two = dp[i-2];

            dp[i] = one+two;
        }

        return dp[n];
    }
};