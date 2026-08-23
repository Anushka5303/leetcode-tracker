class Solution {
public:
    bool sumGame(string num) {
        //first alice
        int n = num.size();
        int left=0, right = n/2;
        int lcnt=0,rcnt=0;
        int lsum = 0, rsum =0;

        while(right<n){
            if(num[left]=='?'){
                lcnt++;
            }else{
                lsum += (num[left]-'0');
            }

            if(num[right]=='?'){
                rcnt++;
            }else{
                rsum += (num[right]-'0');
            }

            left++;
            right++;
        }

        if(lcnt==0 && rcnt==0){
            return lsum != rsum;
        }

        // Alice gets one extra move
        if ((lcnt + rcnt) % 2 == 1) {
            return true;
        }

        // Bob wins only in this exact balancing situation
        return lsum - rsum != (rcnt - lcnt) * 9 / 2;

        

    }
};