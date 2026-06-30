class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int i=0,j=0;
        long long sum=0,ans=0;

        while(j<n){
            if(mp.find(nums[j])==mp.end()){
                sum += nums[j];
                mp[nums[j]] = j;
            }else{
                // sum=nums[j];
                // if(mp[nums[j]]+1>i) i=mp[nums[j]]+1;
                // mp[nums[j]] = j;
                 if(mp[nums[j]] >= i){
                    // i ko ek-ek karke move karo aur sum se subtract karo
                    while(i <= mp[nums[j]]){
                        sum -= nums[i];
                        i++;
                    }
                }
                sum += nums[j];      // naya occurrence add karo
                mp[nums[j]] = j;
            }

            if(j-i+1==k){
                ans = max(ans,sum);
            }
            if(j-i+1>k){
                sum-=nums[i];
                
                mp.erase(mp[nums[i]]);
                ans = max(ans,sum);
                i++;
            }
            j++;
        }
        return ans;

        
    }
};