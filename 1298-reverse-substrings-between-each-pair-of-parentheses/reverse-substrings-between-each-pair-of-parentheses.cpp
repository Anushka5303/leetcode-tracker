class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";

        for(char ch : s) {

            if(ch == '(') {
                // Save whatever we have before '('
                st.push(curr);
                curr = "";
            }
            else if(ch == ')') {
                // Reverse current innermost string
                reverse(curr.begin(), curr.end());

                // Add it to the previous level
                curr = st.top() + curr;
                st.pop();
            }
            else {
                curr += ch;
            }
        }

        return curr;
    }
};