class Solution {
public:
    int tribonacci(int n) {
        int a = 0;
        int b = 1;
        int c = 1;
        int ans = 0;
        if(n<=1) return n;
        for(int i=2; i<n; i++){
            int d = a+b+c;
            a=b;
            b=c;
            c=d;  
        }
        return c;
    }
};