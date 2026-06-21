class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());

        int ans=0;
        int i=0;

        while(i<costs.size() && costs[i]<=coins && coins>=1){
            coins -= costs[i];
            ans++;
            i++;
        }
        return ans;
    }
};