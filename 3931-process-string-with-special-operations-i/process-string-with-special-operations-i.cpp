class Solution {
public:
    string processStr(string s) {
        
        int n = s.size();
        string ans;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                ans += s[i];
            }else if(s[i]=='*')
            {
                if(ans.size()>=1)
                {
                    ans = ans.erase(ans.size()-1,1);
                }
            }else if(s[i]=='#')
            {
                ans+=ans;
            }else{
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};