class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxLen = 1;
        int startIndex = 0;

        // Length = 1 (single characters)
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Length = 2
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = true;

                if(maxLen < 2) {
                    maxLen = 2;
                    startIndex = i;
                }
            }
        }

        // Length >= 3
        for(int length = 3; length <= n; length++) {

            for(int start = 0; start <= n - length; start++) {

                int end = start + length - 1;

                if(s[start] == s[end] && dp[start + 1][end - 1]) {
                    dp[start][end] = true;

                    if(length > maxLen) {
                        maxLen = length;
                        startIndex = start;
                    }
                }
            }
        }

        return s.substr(startIndex, maxLen);
    }
};