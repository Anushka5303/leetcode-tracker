class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // BFS to find max depth
        queue<int> q;
        vector<int> depth(n + 1, -1);
        
        q.push(1);
        depth[1] = 0;
        
        int maxDepth = 0;
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            
            for (int nei : adj[node]) {
                if (depth[nei] == -1) {
                    depth[nei] = depth[node] + 1;
                    maxDepth = max(maxDepth, depth[nei]);
                    q.push(nei);
                }
            }
        }
        
        // Compute 2^(maxDepth - 1) % mod
        const int MOD = 1e9 + 7;
        long long result = 1;
        
        int power = maxDepth - 1;
        long long base = 2;
        
        while (power > 0) {
            if (power & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            power >>= 1;
        }
        
        return (int)result;
    }
};