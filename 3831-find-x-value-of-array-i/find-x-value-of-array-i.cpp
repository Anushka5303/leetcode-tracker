class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int x = num % k;

            vector<long long> ndp(k, 0);

            // start a new subarray
            ndp[x]++;

            // extend previous subarrays
            for (int rem = 0; rem < k; rem++) {
                if (dp[rem] == 0) continue;

                int newRem = (rem * x) % k;
                ndp[newRem] += dp[rem];
            }

            // add all subarrays ending here
            for (int rem = 0; rem < k; rem++) {
                ans[rem] += ndp[rem];
            }

            dp = move(ndp);
        }

        return ans;
    }
};