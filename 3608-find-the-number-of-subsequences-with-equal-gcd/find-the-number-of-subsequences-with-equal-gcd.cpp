class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int maxVal = *max_element(nums.begin(), nums.end());

        // gcd table precompute (0..maxVal)
        vector<vector<int>> g(maxVal + 1, vector<int>(maxVal + 1));
        for (int i = 0; i <= maxVal; i++)
            for (int j = 0; j <= maxVal; j++)
                g[i][j] = __gcd(i, j);

        // dp[g1][g2]
        vector<vector<long long>> dp(maxVal + 1, vector<long long>(maxVal + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<long long>> ndp = dp; // "ignore x" case pehle se copy ho gaya

            for (int g1 = 0; g1 <= maxVal; g1++) {
                for (int g2 = 0; g2 <= maxVal; g2++) {
                    long long val = dp[g1][g2];
                    if (!val) continue;

                    int ng1 = (g1 == 0) ? x : g[g1][x];
                    ndp[ng1][g2] = (ndp[ng1][g2] + val) % MOD;

                    int ng2 = (g2 == 0) ? x : g[g2][x];
                    ndp[g1][ng2] = (ndp[g1][ng2] + val) % MOD;
                }
            }
            dp = move(ndp);
        }

        long long ans = 0;
        for (int g = 1; g <= maxVal; g++)
            ans = (ans + dp[g][g]) % MOD;

        return (int)ans;
    }
};