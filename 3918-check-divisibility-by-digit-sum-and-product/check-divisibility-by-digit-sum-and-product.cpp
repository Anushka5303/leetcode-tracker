class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;

        int cpy = n;

        while(cpy){
            sum+=(cpy%10);
            prod*=(cpy%10);

            cpy/=10;
        }

        return n%(sum+prod)==0;
    }
};