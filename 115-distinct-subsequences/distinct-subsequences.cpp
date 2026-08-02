class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        vector<vector<double>> dp(n1+1,vector<double>(n2+1,0));

        // return magic(s,t,i-1,j-1,dp);
        for(int i=0; i<=n1; i++) dp[i][0] = 1;

        // for(int i=0; i<=n2; i++) dp[0][i] = 0;

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (int)dp[n1][n2];
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