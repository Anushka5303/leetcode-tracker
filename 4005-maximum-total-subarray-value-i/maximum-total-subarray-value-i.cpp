class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        
        int large = *max_element(nums.begin(), nums.end());
        int small = *min_element(nums.begin(), nums.end());

        long long diff = large - small;

        return diff*k;
    }
};