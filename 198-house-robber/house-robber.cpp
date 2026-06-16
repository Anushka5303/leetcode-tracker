class Solution {
public:
    int rob(vector<int>& nums) {
        return magic(nums);
    }
private:
    int magic(vector<int>& nums)
    {
        int prev2 = 0;
        int prev = nums[0];

        int n = nums.size();

        for(int i=1; i<n; i++)
        {
            int pick = nums[i] + prev2;
            int notPick = 0 + prev;

            int cur = max(pick,notPick);

            prev2 = prev;
            prev = cur;
        }

        return prev;
    }
};