class Solution {
public:
    int maxProduct(int n) {
        int ans = 1;
        vector<int> v;

        int a = n;

        while(a){
            v.push_back(a%10);
            a=a/10;
        }
        sort(v.begin(),v.end());

        return v[v.size()-1]*v[v.size()-2];
        
    }
};