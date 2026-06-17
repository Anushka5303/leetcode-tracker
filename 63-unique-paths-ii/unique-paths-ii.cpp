class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = obstacleGrid.size();
        int j = obstacleGrid[0].size();
        
        vector<vector<int>> dp(i,vector<int>(j,-1));
        if(dp[i-1][j-1]==1) return  0;
        dp[i-1][j-1]=1;
        return magic(obstacleGrid,i,j,0,0,dp);
    }
private:
    int magic(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j,
    vector<vector<int>>& dp){
        
        if(i==m-1 && j==n-1 && obstacleGrid[i][j]!=1) return dp[i][j];

        if(i==m || j==n || obstacleGrid[i][j] == 1) return 0;

       if(dp[i][j] != -1) return dp[i][j];

        int right = magic(obstacleGrid,m,n,i+1,j,dp);
        int down = magic(obstacleGrid,m,n,i,j+1,dp);

        return dp[i][j]=right+down;
    }
};