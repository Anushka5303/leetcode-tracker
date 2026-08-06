class Solution {
public:
    int smallestNumber(int n, int t) {
        int a = n;
        bool flag = true;

        while(flag){
            if(magic(a)%t==0){
                flag = false;
                return a;
            }
            else{
                a++;
            }
        }

        return 0;
    }
int magic(int a){
    int ans = 1;
    while(a){
        ans*=(a%10);
        a = a/10;
    }
    return ans;
}
};