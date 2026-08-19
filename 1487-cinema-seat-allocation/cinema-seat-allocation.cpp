class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        sort(reservedSeats.begin(), reservedSeats.end());

        int ans = 2 * n;

        int s = reservedSeats.size();

        for(int k = 0; k < s; ) {

            vector<int> dp(10, 0);

            int row = reservedSeats[k][0];

            // Store all reserved seats of this row
            while(k < s && reservedSeats[k][0] == row) {
                dp[reservedSeats[k][1] - 1] = 1;
                k++;
            }

            int i = 0, j = 0;
            bool start = false;

            int cnt = 0;

            while(j < 10) {

                if(dp[j] == 0 && (j == 1 || j == 3 || j == 5)) {
                    start = true;
                }

                if(dp[j] == 1) {
                    start = false;
                    i = 0;
                }

                if(start == true && dp[j] == 0)
                    i++;

                if(i == 4) {
                    cnt++;
                    i = 0;
                    start = false;
                }

                j++;
            }

            // Initially every row was counted as 2
            ans -= (2 - cnt);
        }

        return ans;
    }
};