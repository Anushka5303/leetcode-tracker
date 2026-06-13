class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string ans = "";
        string map = "abcdefghijklmnopqrstuvwxyz";
        int n = words.size();

        for(int i=0; i<n; i++){
            int sum = 0;
            int l = words[i].size();

            for(int j=0; j<l; j++){
                sum += weights[words[i][j]-'a'];
            }

            ans += map[abs(sum%26 - 26)-1];
        }
        return ans;

    }
};