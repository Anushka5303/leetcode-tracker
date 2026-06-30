class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.size();
        int n2 = needle.size();
        bool flag = false;
        for(int i=0; i<=n-n2; i++){
            for(int j=i; j<i+n2; j++){
                if(haystack[j]==needle[j-i]) {
                    flag=true;
                    continue;
                }else{
                    flag=false;
                    break;
                }
            }
            if(flag==true) return i;
        }
        return -1;
    }
};