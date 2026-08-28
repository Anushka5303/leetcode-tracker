class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        //1 >buy
        //0 >sell

        dp[0][1] = -prices[0];

        if(n>=2){
        dp[1][0] = max(prices[1] + dp[0][1], dp[0][0]);

        dp[1][1] = max(-prices[1] + dp[0][0], dp[0][1]);
        }

        for(int i=2; i<n; i++){
            dp[i][0] = max(prices[i] + dp[i-1][1], dp[i-1][0]);

            dp[i][1] = max(-prices[i] + dp[i-2][0], dp[i-1][1]);
        }

        return dp[n-1][0];
    }
};