class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int dif = target - nums[i];

            auto it = find(nums.begin() + i + 1, nums.end(), dif);

            if (it != nums.end()) {
                int j = it - nums.begin();
                return {i, j};
            }
        }

        return {};
    }
};