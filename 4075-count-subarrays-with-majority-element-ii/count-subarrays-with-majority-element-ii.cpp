class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // Step 1: Transform array
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) arr[i] = 1;
            else arr[i] = -1;
        }

        // Step 2: Prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        // Step 3: Coordinate compression
        vector<int> sorted = prefix;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        auto getIndex = [&](int x) {
            return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1;
        };

        // Fenwick Tree
        vector<int> BIT(sorted.size() + 1, 0);

        auto update = [&](int i) {
            while (i < BIT.size()) {
                BIT[i]++;
                i += i & -i;
            }
        };

        auto query = [&](int i) {
            int s = 0;
            while (i > 0) {
                s += BIT[i];
                i -= i & -i;
            }
            return s;
        };

        long long ans = 0;

        for (int i = 0; i <= n; i++) {
            int idx = getIndex(prefix[i]);

            // count how many prefix[j] < prefix[i]
            ans += query(idx - 1);

            update(idx);
        }

        return ans;
    }
};