class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0,ans=0;

        for(int i=0; i<k && i<n; i++){
            sum += cardPoints[i];
        }
        ans=max(ans,sum);

        int j=0;
        for(int i=n-1 ; i>=n-k && i>=0; i--){
            if(k-j>=0) sum -= cardPoints[k-j-1];
            j++;
            sum += cardPoints[i];
            ans = max(ans,sum);
        }

        return ans;
    }
};