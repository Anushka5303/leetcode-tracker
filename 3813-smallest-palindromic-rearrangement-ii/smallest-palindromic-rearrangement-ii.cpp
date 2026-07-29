#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Half frequencies
        vector<int> half_freq(26, 0);
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            half_freq[i] = freq[i] / 2;
            if (freq[i] % 2 != 0) {
                mid_char = 'a' + i;
            }
        }

        int half_len = n / 2;

        // Function to calculate multinomial coefficient capped at 10^6 + 1
        auto countPermutations = [&](vector<int>& f, int total_len) -> long long {
            long long cap = 1e6 + 5;
            long long res = 1;
            int current_len = 0;

            for (int count : f) {
                for (int i = 1; i <= count; ++i) {
                    current_len++;
                    res = res * current_len / i;
                    if (res > cap) {
                        res = cap; // Prevent overflow beyond what k needs
                    }
                }
            }
            return res;
        };

        // Check if k exceeds total available permutations
        long long total_perms = countPermutations(half_freq, half_len);
        if (total_perms < k) {
            return "";
        }

        string half_res = "";
        long long current_k = k;

        // Construct the first half lexicographically
        for (int pos = 0; pos < half_len; ++pos) {
            for (int c = 0; c < 26; ++c) {
                if (half_freq[c] > 0) {
                    half_freq[c]--; // Try using character 'a' + c
                    long long perms = countPermutations(half_freq, half_len - 1 - pos);

                    if (current_k <= perms) {
                        // Character fits here
                        half_res += (char)('a' + c);
                        break;
                    } else {
                        // Skip these permutations and adjust k
                        current_k -= perms;
                        half_freq[c]++; // Backtrack
                    }
                }
            }
        }

        // Reconstruct the full palindrome
        string full_res = half_res;
        if (mid_char != 0) {
            full_res += mid_char;
        }
        string second_half = half_res;
        reverse(second_half.begin(), second_half.end());
        full_res += second_half;

        return full_res;
    }
};