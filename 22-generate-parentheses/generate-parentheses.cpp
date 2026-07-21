class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds = "";
        magic(n,ans,ds,0,0);
        return ans;
    }
private:
    void magic(int n, vector<string>& ans, string ds, int open, int close){
        if(ds.size() == n*2){
            ans.push_back(ds);
        }

        if(open < n){
            ds+='(';
            magic(n,ans,ds,open+1,close);
            ds.pop_back();
        }
        if(close<open){
            ds+=')';
            magic(n,ans,ds,open,close+1);
            ds.pop_back();
        }
    }
};