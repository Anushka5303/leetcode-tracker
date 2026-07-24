class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int v : nums) {
            auto ndp = dp;   // option of taking this element 0 times

            for (int p = 0; p <= 3; p++) {
                for (int x = 0; x < MAXX; x++) {
                    if (!dp[p][x]) continue;

                    // take once
                    if (p + 1 <= 3)
                        ndp[p + 1][x ^ v] = true;

                    // take twice
                    if (p + 2 <= 3)
                        ndp[p + 2][x] = true;

                    // take three times
                    if (p + 3 <= 3)
                        ndp[p + 3][x ^ v] = true;
                }
            }

            dp.swap(ndp);
        }

        int ans = 0;
        for (int x = 0; x < MAXX; x++)
            if (dp[3][x]) ans++;

        return ans;
    }
};