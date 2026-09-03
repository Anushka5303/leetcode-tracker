class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestOdd = INT_MAX;
        int smallestEven = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 0) {
                smallestEven = min(smallestEven, x);
            } else {
                smallestOdd = min(smallestOdd, x);
            }
        }

        // Already all even or all odd
        if (smallestOdd == INT_MAX || smallestEven == INT_MAX) {
            return true;
        }

        // Make every even number odd using the smallest odd number
        return smallestOdd < smallestEven;
    }
};