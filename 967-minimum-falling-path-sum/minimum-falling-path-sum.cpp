class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));

        for(int i=0; i<n; i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                // if(dp[i][j] != -1) continue;
                int left = INT_MAX;
                int down = matrix[i][j] + dp[i+1][j];
                int right = INT_MAX;

                if(j-1>=0) left = matrix[i][j] + dp[i+1][j-1];
                if(j+1<n) right = matrix[i][j] + dp[i+1][j+1];

                dp[i][j] = min(left,min(down,right));
            }
        }

        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,dp[0][i]);
        }
        return ans;
    }
};