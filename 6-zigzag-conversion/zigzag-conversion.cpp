class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows==1 || numRows>=s.size()) return s;
        vector<string> ans(numRows);

        int curR = 0;

        bool flag = false;

        for(char c: s){
            ans[curR] += c;

            if(curR==0 || curR==numRows-1) flag = !flag;

            curR += flag? 1:-1;
        }

        string an = "";

        for(int i=0;i<numRows; i++){
            for(char c:ans[i]){
                an+=c;
            }
        }

        return an;


    }
};