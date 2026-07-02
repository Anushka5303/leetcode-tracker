class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        queue<pair<int,int>> q;
        q.push({0,0});
        best[0][0] = startHealth;

        vector<pair<int,int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            int currHealth = best[x][y];

            if(x == m-1 && y == n-1)
                return true;

            for(auto &[dx,dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int newHealth = currHealth - grid[nx][ny];

                if(newHealth <= 0)
                    continue;

                if(newHealth > best[nx][ny]) {
                    best[nx][ny] = newHealth;
                    q.push({nx,ny});
                }
            }
        }

        return false;
    }
};