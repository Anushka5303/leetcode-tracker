class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // treat * as ')'
                high++;  // treat * as '('
            }

            // We cannot have negative unmatched '('
            low = max(0, low);

            // Even maximum possible opens became negative
            if (high < 0) {
                return false;
            }
        }

        return low == 0;
    }
};