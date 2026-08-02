class Solution {
public:
    int numDistinct(string s, string t) {
        int i = s.size();
        int j = t.size();

        vector<vector<int>> dp(i+1,vector<int>(j+1,-1));

        return magic(s,t,i-1,j-1,dp);
    }

private:
int magic(string s, string t, int i, int j,vector<vector<int>>& dp){
    if(j<0) return 1;
    if(i<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]){
        return dp[i][j]=magic(s,t,i-1,j-1,dp) + magic(s,t,i-1,j,dp);
    }else{
        return dp[i][j]=magic(s,t,i-1,j,dp);
    }
}
};