class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mp;
        int n = s.size();

        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }

        vector<char> ans(n); 

        int i=0;

        int n2 = mp.size();

        for(auto m: mp){
            int c = m.second/2;
            int rem = m.second%2;

            while(c){
                ans[i]=m.first;
                ans[n-1-i]=m.first;
                c--;
                i++;
            }

            // if(rem==0){
            //     m.second=0;
            // }else{
            //     m.second = 1;
            // }

        }

        for (auto m : mp) {
            if (m.second % 2 == 1) {
                ans[n / 2] = m.first;
                break;
            }
        }

        return string(ans.begin(), ans.end());
    }
};