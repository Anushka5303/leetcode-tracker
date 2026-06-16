class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int> v1(nums.begin()+1, nums.end());
        vector<int> v2(nums.begin(), nums.end()-1);
        int a = magic(v1);
        int b = magic(v2);

        return max(a,b);
    }

private:
    int magic(vector<int>& nums){

        int prev2 = 0;
        int prev = nums[0];

        int n = nums.size();

        for(int i=1; i<n; i++){

            int pick = nums[i] + prev2;
            int notPick = 0 + prev;

            int cur = max(pick,notPick);

            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};