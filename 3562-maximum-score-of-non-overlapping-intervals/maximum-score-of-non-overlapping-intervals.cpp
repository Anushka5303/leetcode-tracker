class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store: {left, right, weight, original_index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting position
        sort(a.begin(), a.end());

        // next[i] = first interval whose start > a[i].right
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            next[i] = lo;
        }

        // dp[i][k] = best result from i onward using at most k intervals
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));

        // choice[i][k] = indices chosen for the best result
        vector<vector<vector<int>>> choice(
            n + 1,
            vector<vector<int>>(5)
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: skip current interval
                long long skipScore = dp[i + 1][k];
                vector<int> skipList = choice[i + 1][k];

                // Option 2: take current interval
                long long takeScore =
                    a[i][2] + dp[next[i]][k - 1];

                vector<int> takeList = choice[next[i]][k - 1];

                takeList.push_back((int)a[i][3]);

                // We need lexicographically smallest list,
                // so sort the selected original indices.
                sort(takeList.begin(), takeList.end());

                if (takeScore > skipScore) {
                    dp[i][k] = takeScore;
                    choice[i][k] = takeList;
                }
                else if (takeScore < skipScore) {
                    dp[i][k] = skipScore;
                    choice[i][k] = skipList;
                }
                else {
                    // Same score -> lexicographically smaller list
                    if (takeList < skipList) {
                        dp[i][k] = takeScore;
                        choice[i][k] = takeList;
                    }
                    else {
                        dp[i][k] = skipScore;
                        choice[i][k] = skipList;
                    }
                }
            }
        }

        return choice[0][4];
    }
};
