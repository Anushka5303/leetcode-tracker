class Solution {
public:
    int missingInteger(vector<int>& nums) {

        // Step 1: Find sum of longest sequential prefix
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }

        // Step 2: Find smallest missing integer >= sum
        unordered_set<int> st(nums.begin(), nums.end());

        while (st.count(sum)) {
            sum++;
        }

        return sum;
    }
};