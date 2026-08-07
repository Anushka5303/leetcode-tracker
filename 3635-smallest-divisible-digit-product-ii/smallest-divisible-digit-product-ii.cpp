class Solution {
public:
    const int INF = 1e9;
    int dp[50][35];

    int fac[10][4] = {
        {0,0,0,0}, // 0
        {0,0,0,0}, // 1
        {1,0,0,0}, // 2
        {0,1,0,0}, // 3
        {2,0,0,0}, // 4
        {0,0,1,0}, // 5
        {1,1,0,0}, // 6
        {0,0,0,1}, // 7
        {3,0,0,0}, // 8
        {0,2,0,0}  // 9
    };

    // Minimum digits needed to supply AT LEAST 2^a * 3^b
    int solve23(int a, int b) {
        if (a == 0 && b == 0) return 0;

        int &res = dp[a][b];
        if (res != -1) return res;

        res = INF;
        for (int digit = 2; digit <= 9; digit++) {
            int na = max(0, a - fac[digit][0]);
            int nb = max(0, b - fac[digit][1]);
            int cur = solve23(na, nb);
            if (cur != INF) res = min(res, 1 + cur);
        }
        return res;
    }

    // Can `slots` FREE digits (1..9) supply 2^a * 3^b * 5^c * 7^d ?
    bool possible(int a, int b, int c, int d, int slots) {
        if (slots < 0) return false;
        int need5and7 = c + d;
        if (need5and7 > slots) return false;
        int need23 = solve23(a, b);
        if (need23 == INF) return false;
        return need23 + need5and7 <= slots;
    }

    // Smallest zero-free string of length `len`, digits fully free (1..9),
    // satisfying remaining need2/3/5/7. Caller must ensure possible(...) is true.
    string buildFree(int len, int need2, int need3, int need5, int need7) {
        string ans;
        ans.reserve(len);

        for (int pos = 0; pos < len; pos++) {
            for (int digit = 1; digit <= 9; digit++) {
                int n2 = max(0, need2 - fac[digit][0]);
                int n3 = max(0, need3 - fac[digit][1]);
                int n5 = max(0, need5 - fac[digit][2]);
                int n7 = max(0, need7 - fac[digit][3]);

                int remaining = len - pos - 1;
                if (!possible(n2, n3, n5, n7, remaining)) continue;

                ans.push_back('0' + digit);
                need2 = n2; need3 = n3; need5 = n5; need7 = n7;
                break;
            }
        }
        return ans;
    }

    string smallestNumber(string num, long long t) {
        memset(dp, -1, sizeof(dp));

        // ---------------------------------------
        // Factorize t
        // ---------------------------------------
        int need2 = 0, need3 = 0, need5 = 0, need7 = 0;
        while (t % 2 == 0) { need2++; t /= 2; }
        while (t % 3 == 0) { need3++; t /= 3; }
        while (t % 5 == 0) { need5++; t /= 5; }
        while (t % 7 == 0) { need7++; t /= 7; }

        if (t != 1) return "-1"; // leftover prime factor > 7, impossible

        int n = num.size();

        // ---------------------------------------
        // Prefix scan: needs remaining after consuming num[0..i-1]
        // ---------------------------------------
        vector<int> preA(n + 1), preB(n + 1), preC(n + 1), preD(n + 1);
        preA[0] = need2; preB[0] = need3; preC[0] = need5; preD[0] = need7;

        int firstZero = n;
        for (int i = 0; i < n; i++) {
            int dgt = num[i] - '0';
            if (dgt == 0 && firstZero == n) firstZero = i;

            preA[i+1] = max(0, preA[i] - fac[dgt][0]);
            preB[i+1] = max(0, preB[i] - fac[dgt][1]);
            preC[i+1] = max(0, preC[i] - fac[dgt][2]);
            preD[i+1] = max(0, preD[i] - fac[dgt][3]);
        }

        // ---------------------------------------
        // Case A: num itself already works
        // ---------------------------------------
        if (firstZero == n &&
            preA[n] == 0 && preB[n] == 0 && preC[n] == 0 && preD[n] == 0) {
            return num;
        }

        // ---------------------------------------
        // Case B: same length, strictly greater than num.
        // Increase digit at the RIGHTMOST feasible position
        // (must be at/before first zero, so kept prefix stays zero-free).
        // Everything after this position is fully free (not tight anymore),
        // so possible()/buildFree() are valid here.
        // ---------------------------------------
        int limit = min(n - 1, firstZero);

        for (int i = limit; i >= 0; i--) {
            int a = preA[i], b = preB[i], c = preC[i], d = preD[i];
            int startDigit = (num[i] - '0') + 1;

            for (int digit = startDigit; digit <= 9; digit++) {
                int na = max(0, a - fac[digit][0]);
                int nb = max(0, b - fac[digit][1]);
                int nc = max(0, c - fac[digit][2]);
                int nd = max(0, d - fac[digit][3]);

                int remaining = n - i - 1;
                if (!possible(na, nb, nc, nd, remaining)) continue;

                string suffix = buildFree(remaining, na, nb, nc, nd);
                return num.substr(0, i) + char('0' + digit) + suffix;
            }
        }

        // ---------------------------------------
        // Case C: need more digits than num has
        // ---------------------------------------
        int minDigits = solve23(need2, need3) + need5 + need7;
        int len = max(n + 1, minDigits);

        if (!possible(need2, need3, need5, need7, len)) return "-1";

        return buildFree(len, need2, need3, need5, need7);
    }
};