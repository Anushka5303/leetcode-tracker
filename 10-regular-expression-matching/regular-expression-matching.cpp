class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,0));
        return magic(s,p,0,0,dp);
    }
private:
    bool magic(string s,string p,int i,int j,vector<vector<int>>& dp){
        if(j==p.size()){
            if(i==s.size()) return true;
            return false;
        }
        if(dp[i][j] !=0 ) return dp[i][j] == 1;
        
        bool match = (i<s.size() && (s[i]==p[j] || p[j]=='.'))?true:false;

        bool result;
        if((j+1) < p.size() && p[j+1]=='*'){
            result =  magic(s,p,i,j+2,dp) || (match && magic(s,p,i+1,j,dp));
        }else{
            result =  match && magic(s,p,i+1,j+1,dp);
        }
        dp[i][j] = result?1:-1;
        return result;
    }
};