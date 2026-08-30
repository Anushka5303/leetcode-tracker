class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find positions of minimum and maximum
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        // Make minIndex the smaller position
        if (minIndex > maxIndex)
            swap(minIndex, maxIndex);

        // 1. Remove both from front
        int fromFront = maxIndex + 1;

        // 2. Remove both from back
        int fromBack = n - minIndex;

        // 3. Remove min from front, max from back
        int oneFrontOneBack = (minIndex + 1) + (n - maxIndex);

        return min({fromFront, fromBack, oneFrontOneBack});
    }
};