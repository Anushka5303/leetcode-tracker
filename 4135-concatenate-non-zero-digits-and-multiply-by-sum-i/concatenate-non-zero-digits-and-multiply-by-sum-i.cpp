class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long copy = n;
        long long mul = 0;

        while(copy){
            long long r = copy%10;
            if(r!=0) sum = sum*10 + r;
            mul += r;
            copy = copy/10;

        }

        long long ans = 0;

        while(sum){
            long long r = sum%10;
            ans = ans*10 + r;
            sum = sum/10;
        }
        

        return ans*mul;

    }
};