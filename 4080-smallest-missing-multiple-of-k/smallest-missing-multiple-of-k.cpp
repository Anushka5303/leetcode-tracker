class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        int ans = k;
        int j = 1;

        int i=0;
        while(i<n && ans>=nums[i]){
            if(ans==nums[i]){
                j++;
                ans = k*j;
            }
            i++;
        }

        return ans;
    }
};