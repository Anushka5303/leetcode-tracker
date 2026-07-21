class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<unsigned int>> dp(
            n, vector<unsigned int>(amount + 1, 0)
        );

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {

                unsigned int ex = dp[i - 1][j];

                unsigned int in = 0;

                if (coins[i] <= j) {
                    in = dp[i][j - coins[i]];
                }

                dp[i][j] = ex + in;
            }
        }

        return dp[n - 1][amount];
    }
};