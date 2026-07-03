class Solution {
public:
    bool canAchieve(int score, vector<vector<int>>& edges,
                    vector<bool>& online, long long k, int n) {

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            if (cost < score) continue;

            if (u != 0 && u != n - 1 && !online[u]) continue;
            if (v != 0 && v != n - 1 && !online[v]) continue;

            adj[u].push_back({v, cost});
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, cost] : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;

        for (int u : topo) {
            if (dist[u] == INF) continue;

            for (auto &[v, cost] : adj[u]) {
                dist[v] = min(dist[v], dist[u] + cost);
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        int lo = 0, hi = 0;
        for (auto &e : edges)
            hi = max(hi, e[2]);

        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (canAchieve(mid, edges, online, k, n)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};