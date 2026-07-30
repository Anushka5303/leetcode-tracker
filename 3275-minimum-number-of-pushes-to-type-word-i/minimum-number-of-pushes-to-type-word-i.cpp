class Solution {
public:
    int minimumPushes(string word) {
        int count = 26;
        int keys = 8;

        int n = word.size();

        if(n<=keys) return n;
        
        int ans = keys;
        n-=keys;
        
        if(n<=keys) return ans+(n*2);

        ans+=(keys*2);

        n-=keys;
        if(n<=keys) return ans+(n*3);

        ans += keys * 3;
        n -= keys;          // <-- Missing line

        return ans + n * 4;
        
    }
};