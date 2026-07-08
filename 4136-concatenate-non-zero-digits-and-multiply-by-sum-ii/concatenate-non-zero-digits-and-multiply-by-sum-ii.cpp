class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        const long long MOD = 1e9 + 7;

        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) pow10[i] = (pow10[i-1] * 10) % MOD;

        vector<long long> prefixVal(n + 1, 0);      // non-zero digits ka concatenated value
        vector<long long> prefixCount(n + 1, 0);    // non-zero digits ka count
        vector<long long> prefixDigitSum(n + 1, 0); // sabhi digits ka sum

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            prefixDigitSum[i+1] = prefixDigitSum[i] + d;
            if (d != 0) {
                prefixVal[i+1] = (prefixVal[i] * 10 + d) % MOD;
                prefixCount[i+1] = prefixCount[i] + 1;
            } else {
                prefixVal[i+1] = prefixVal[i];
                prefixCount[i+1] = prefixCount[i];
            }
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            if (l > r) { ans.push_back(0); continue; }

            long long cnt = prefixCount[r+1] - prefixCount[l];
            long long val = ((prefixVal[r+1] - prefixVal[l] * pow10[cnt]) % MOD + MOD) % MOD;
            long long mulSum = prefixDigitSum[r+1] - prefixDigitSum[l];

            long long res = (val * (mulSum % MOD)) % MOD;
            ans.push_back((int)res);
        }
        return ans;
    }
};