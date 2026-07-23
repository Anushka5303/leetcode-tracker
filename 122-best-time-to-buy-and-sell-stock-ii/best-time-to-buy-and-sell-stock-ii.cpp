class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int buy = 1;
        // int i = 0;

        // return magic(prices,i,buy);   
        int n  = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][1] = -prices[0];

        for(int i=1; i<n; i++){
            dp[i][1] = max(-prices[i] + dp[i-1][0], dp[i-1][1]);
            dp[i][0] = max(prices[i]+dp[i-1][1], dp[i-1][0]);
        }

        return dp[n-1][0];

    }

private:
int magic(vector<int>& prices, int i, int buy){
    if(i==prices.size()){
        return 0;
    }

    int pur = 0,sell=0;
    if(buy){
        pur = max(-prices[i] + magic(prices,i+1,0), magic(prices,i+1,1));

    }else{
        sell = max(prices[i] + magic(prices,i+1,1), magic(prices,i+1,0));
    }

    return max(pur,sell);
}    
};