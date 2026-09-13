class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        vector<pair<int,int>> one1, one2;

        int n = img1.size();
        int m = img1[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(img1[i][j]==1){
                    one1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    one2.push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int> mp;
        int ans = 0;
        for(auto one11: one1){
            for(auto one22: one2){
                int dr = one22.first - one11.first;
                int dc = one22.second - one11.second;

                mp[{dr,dc}]++;

                ans = max(ans,mp[{dr,dc}]);
            }
        }
        
        return ans;
    }
};