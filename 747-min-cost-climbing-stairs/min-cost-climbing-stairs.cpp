class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0];
        int prev = cost[1];

        int ans = min(prev2,prev);

        for(int i=2; i<n; i++){
            int jump = cost[i] + min(prev2,prev);
            prev2 = prev;
            prev = jump;
        }

        return min(prev2,prev);
    }
};