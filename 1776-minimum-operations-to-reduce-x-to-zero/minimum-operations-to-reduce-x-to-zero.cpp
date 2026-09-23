class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }

        int target = sum-x;

        if(target < 0) return -1;

        if(target == 0) return n;

        int i=0,j=0;
        int ans = 0;
        int add = 0;

        while(j<n){
            add+=nums[j];
            while(add>target && i<=j){
                add-=nums[i];
                i++;
            }

            if(add==target){
                ans = max(ans,j-i+1);
            }

            j++;
        }

        if(ans>0) return n-ans;
        return -1;
    }
};