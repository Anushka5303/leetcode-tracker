class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        magic(s,0,ds,ans);

        return ans;
    }
private:
    void magic(string s,int i,vector<string>& ds, vector<vector<string>>& ans){
        if(i==s.size()){
            ans.push_back(ds);
        }

        for(int j=i; j<s.size(); j++){
            if(isPalin(s,i,j)){
                ds.push_back(s.substr(i,j-i+1));
                magic(s,j+1,ds,ans);
                ds.pop_back();
            }
        }
    }

    bool isPalin(string s,int start, int last){

        while(start<last && s[start]==s[last]){
            start++;
            last--;
        }

        return start>=last;
    }

    
};