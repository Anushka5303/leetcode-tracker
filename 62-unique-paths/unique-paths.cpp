class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[m-1][n-1] = 1;
        return magic(m,n,0,0,dp);
    }
    int magic(int m, int n, int i, int j,vector<vector<int>>& dp)
    {   
        
        if( i==m-1 && j==n-1)
        {
            return dp[m-1][n-1];
        }

        if(i==m || j==n) return 0; 

        if(dp[i][j] != -1) return dp[i][j];

        int down = magic(m,n,i+1,j,dp);
        int right = magic(m,n,i,j+1,dp);

        return dp[i][j]=down+right;
    }
};