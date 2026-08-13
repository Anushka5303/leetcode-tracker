class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0,j=0;

        int ans = 1;

        int fre = INT_MIN;

        unordered_map<char,int> mp;

        while(j<n){
            mp[s[j]]++;

            fre = max(fre,mp[s[j]]);

            // int chng = (j-i+1) - fre;

            while(((j-i+1) - fre) >k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;    
            }

            ans = max(ans,j-i+1);
            j++;
        }
        return ans;


    }
};