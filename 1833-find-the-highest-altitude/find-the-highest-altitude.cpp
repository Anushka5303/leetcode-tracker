class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int a = 0;
        int ans = a;

        for(int i=0; i<gain.size(); i++)
        {
            a = a + gain[i];
            ans = max(ans,a);
        }
        return ans;
    }
};