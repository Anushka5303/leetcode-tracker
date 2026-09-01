class Solution {
public:
    struct State {
        int r, c, mask, en;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int k = 0;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } 
                else if (classroom[i][j] == 'L') {
                    litterId[i][j] = k++;
                }
            }
        }

        int fullMask = (1 << k) - 1;

        queue<State> q;

        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        best[sr][sc][0] = energy;
        q.push({sr, sc, 0, energy});

        int dirs[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                State cur = q.front();
                q.pop();

                if (cur.mask == fullMask)
                    return steps;

                if (cur.en == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nr = cur.r + dirs[d][0];
                    int nc = cur.c + dirs[d][1];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int nmask = cur.mask;
                    int nen = cur.en - 1;

                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << litterId[nr][nc]);
                    }

                    if (classroom[nr][nc] == 'R') {
                        nen = energy;
                    }

                    if (best[nr][nc][nmask] >= nen)
                        continue;

                    best[nr][nc][nmask] = nen;
                    q.push({nr, nc, nmask, nen});
                }
            }

            steps++;
        }

        return -1;
    }
};