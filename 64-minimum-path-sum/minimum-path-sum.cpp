class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        dp[m-1][n-1] = grid[m-1][n-1];

        return magic(grid,m,n,0,0,dp);
    }
int magic(vector<vector<int>>& grid,int m,int n,int i,int j,vector<vector<int>>& dp){

    if(i==m-1 && j==n-1) return dp[i][j];

    if(i==m || j==n) return INT_MAX;

    if(dp[i][j] != -1) return dp[i][j];
    
    int right = magic(grid,m,n,i+1,j,dp);
    int down = magic(grid,m,n,i,j+1,dp);

    int res = min(right,down);

    return dp[i][j] = grid[i][j] + res;
}
};