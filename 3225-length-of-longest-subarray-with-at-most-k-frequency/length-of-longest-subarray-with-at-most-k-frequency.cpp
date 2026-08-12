class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mp;
        int ans = 0;
        int n = nums.size();

        int i=0, j=0;

        while(j<n){
            mp[nums[j]]++;
            
            while(mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }
            
            ans = max(ans,j-i+1);
            
            j++;

        }
        return ans;
        
    }
};