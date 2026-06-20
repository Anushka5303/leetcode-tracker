class Solution {
public:
    string longestPalindrome(string s) {
        
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int maxlen = 1;
        int start = 0;
        for(int i=0; i<s.size(); i++) dp[i][i] = true;

        for(int i=0; i<s.size()-1; i++){
            if(s[i]==s[i+1]) {
                dp[i][i+1] = true;
                maxlen = 2;
                start = i;
            }
        }

        for(int i=3; i<=s.size(); i++){

            for(int j=0; j<=s.size()-i; j++){

                int a = j+i-1;
                if(s[j]==s[a] && dp[j+1][a-1]){
                    dp[j][a] = true;

                    if(i>maxlen){
                        maxlen = i;
                        start = j;
                    }
                }
            }

        }
        return s.substr(start,maxlen);
    }
};