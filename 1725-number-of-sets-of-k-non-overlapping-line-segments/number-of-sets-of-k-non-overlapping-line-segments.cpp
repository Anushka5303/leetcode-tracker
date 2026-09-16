class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    }

    long long combination(long long n, long long r) {
        if (r < 0 || r > n)
            return 0;

        long long numerator = 1;
        long long denominator = 1;

        for (long long i = 1; i <= r; i++) {
            numerator = numerator * (n - r + i) % MOD;
            denominator = denominator * i % MOD;
        }

        return numerator * power(denominator, MOD - 2) % MOD;
    }

    int numberOfSets(int n, int k) {
        return combination(n + k - 1, 2 * k);
    }
};