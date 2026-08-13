class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;

        int ans = 0;
        int sum=0,sum2=0;

        while(j<n){
            if(nums[j]%2==1) ans++;

            while(ans>k){
                ans -= nums[i]%2;
                i++;
            }

            sum+= (j-i+1);
            j++;
        }
        i=0,j=0;

        int ans2 = 0;
        

        while(j<n){
            if(nums[j]%2==1) ans2++;

            while(ans2>k-1){
                ans2 -= nums[i]%2;
                i++;
            }

            sum2+= (j-i+1);
            j++;
        }

        return sum-sum2;
    }
};