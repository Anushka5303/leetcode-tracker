class Solution {
public:
    const int MOD = 1e9+7;
    int LOG = 20;
    
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    
    void dfs(int node, int parent) {
        up[node][0] = parent;
        
        for(int i = 1; i < LOG; i++) {
            up[node][i] = up[ up[node][i-1] ][i-1];
        }
        
        for(int nei : adj[node]) {
            if(nei == parent) continue;
            depth[nei] = depth[node] + 1;
            dfs(nei, node);
        }
    }
    
    int lca(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);
        
        int diff = depth[u] - depth[v];
        for(int i = 0; i < LOG; i++) {
            if(diff & (1 << i)) {
                u = up[u][i];
            }
        }
        
        if(u == v) return u;
        
        for(int i = LOG - 1; i >= 0; i--) {
            if(up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        
        return up[u][0];
    }
    
    long long modExp(long long base, long long exp) {
        long long res = 1;
        while(exp) {
            if(exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        
        adj.resize(n+1);
        up.assign(n+1, vector<int>(LOG));
        depth.assign(n+1, 0);
        
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(1, 1);
        
        vector<int> ans;
        
        for(auto &q : queries) {
            int u = q[0], v = q[1];
            
            int L = lca(u, v);
            int k = depth[u] + depth[v] - 2*depth[L];
            
            if(k == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(modExp(2, k-1));
            }
        }
        
        return ans;
    }
};