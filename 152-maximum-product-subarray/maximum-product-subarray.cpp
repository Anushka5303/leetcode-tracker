class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;

        int p1 = 1;
        int p2 = 1;

        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(p1==0) p1 = 1;
            if(p2==0) p2 = 1;

            p1 = p1*nums[i];
            p2 = p2*nums[n-1-i];

            ans = max(ans, max(p1,p2));
        }

        return ans;
    }
};