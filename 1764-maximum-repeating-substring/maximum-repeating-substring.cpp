class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string st ="";
        int ans = 0;


        while(true){
            st+=word;
            if(sequence.find(st) != string::npos){
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
};