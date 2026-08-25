class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //0 -> buy | 1 -> sell
        vector<vector<int>> dp(n,vector<int>(2,0));

        dp[0][0] = -prices[0];
        // dp[0][1] = 0;

        for(int i=1; i<n; i++){
            int buy = -prices[i] + dp[i-1][1];
            int notBuy = dp[i-1][0]; 
            dp[i][0] = max(buy,notBuy);

            int sell = prices[i] + dp[i-1][0];
            int notSell = dp[i-1][1];
            dp[i][1] = max(sell,notSell);
        }

        return dp[n-1][1];
    }
};