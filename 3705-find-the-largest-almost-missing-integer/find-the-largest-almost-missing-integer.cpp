class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> mp;

        // Count in how many subarrays each number appears
        for (int i = 0; i <= n - k; i++) {

            unordered_set<int> st;

            // Current subarray
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Count this subarray only once
            for (int x : st) {
                mp[x]++;
            }
        }

        int ans = -1;

        for (auto i = mp.begin(); i != mp.end(); i++) {

            if (i->second == 1) {
                ans = max(ans, i->first);
            }
        }

        return ans;
    }
};