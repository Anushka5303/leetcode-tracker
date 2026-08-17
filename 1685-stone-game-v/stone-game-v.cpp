class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefixSum(n + 1, 0);

        // prefix sum
        for(int x = 0; x < n; x++){
            prefixSum[x + 1] = prefixSum[x] + stoneValue[x];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // i = length of subarray
        for(int i = 2; i <= n; i++){

            // j = starting index
            for(int j = 0; j + i - 1 < n; j++){

                // ending index
                int end = j + i - 1;

                // k = split point
                for(int k = j; k < end; k++){

                    int left = prefixSum[k + 1] - prefixSum[j];

                    int right = prefixSum[end + 1] - prefixSum[k + 1];

                    if(left > right){

                        // left is removed
                        // Alice gets right
                        dp[j][end] = max(
                            dp[j][end],
                            right + dp[k + 1][end]
                        );
                    }

                    else if(left < right){

                        // right is removed
                        // Alice gets left
                        dp[j][end] = max(
                            dp[j][end],
                            left + dp[j][k]
                        );
                    }

                    else{

                        // Alice can choose either side
                        dp[j][end] = max(
                            dp[j][end],
                            max(
                                left + dp[j][k],
                                right + dp[k + 1][end]
                            )
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};