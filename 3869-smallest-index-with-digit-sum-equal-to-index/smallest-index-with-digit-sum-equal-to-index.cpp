class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i==cnt(nums[i])) return i;
        }
        return -1;
    }
private:
    int cnt(int i){
        int sum = 0;
        while(i){
            sum += i%10;
            i = i/10;
        }

        return sum;
    }
};