class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = nums[0];

        int n = nums.size();

        vector<int> mx;

        for(int i=0; i<n; i++){
            
            maxi = max(maxi,nums[i]);
            mx.push_back(maxi);
        }

        vector<int> prefixGod;

        for(int i=0; i<n; i++){
            prefixGod.push_back(gcd(nums[i],mx[i]));
        }

        sort(prefixGod.begin(), prefixGod.end(), greater<int>());
        
        long long ans = 0;

        int i=0,j=n-1;
        while(i<j){
            ans+=gcd(prefixGod[i],prefixGod[j]);
            i++;
            j--;
        }

        return ans;
    }
private:
int gcd(int a,int b){
    if(a==0) return b;
    if(b==0) return a;

    if(a>=b) return gcd(a%b,b);
    else return gcd(a,b%a);
}
};