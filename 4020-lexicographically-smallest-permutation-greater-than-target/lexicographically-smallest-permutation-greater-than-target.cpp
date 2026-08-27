class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int i = 0;

        // Match target as long as possible
        while (i < n && freq[target[i] - 'a'] > 0) {
            freq[target[i] - 'a']--;
            i++;
        }

        // Start safely from n-1 if complete target was matched
        for (int j = min(i, n - 1); j >= 0; j--) {

            // Restore target[j] if it was previously matched
            if (j < i) {
                freq[target[j] - 'a']++;
            }

            // Find smallest available character > target[j]
            for (int c = target[j] - 'a' + 1; c < 26; c++) {
                if (freq[c] > 0) {

                    string ans = target.substr(0, j);

                    ans += char('a' + c);
                    freq[c]--;

                    // Append remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};