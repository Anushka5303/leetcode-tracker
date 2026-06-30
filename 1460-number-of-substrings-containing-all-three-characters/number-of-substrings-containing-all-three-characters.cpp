class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        int n=s.size();
        int ans = 0;
        unordered_map<char,int> mp;
        mp['a'] = -1;
        mp['b'] = -1;
        mp['c'] = -1;

        while(j<n){
            mp[s[j]] = j;

            if(mp['a']!=-1 && mp['b']!=-1 && mp['c']!=-1){
                i = min(mp['a'],min(mp['b'],mp['c']));
                ans += (i+1);
            }
            j++;
        }

        return ans;
    }
};