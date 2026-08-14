class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i=0,j=0;

        int ans = -1;

        unordered_map<char,int> mp;

        while(j<n){
            mp[s[j]]++;

            while(mp[s[j]]>2){
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