class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for(char c : s) {
            if(c == '(') {
                balance++;
            }
            else if(c == ')') {
                balance--;

                if(balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while(!q.empty()) {

            int n = q.size();

            // Current BFS level
            while(n--) {

                string curr = q.front();
                q.pop();

                if(isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                // If valid strings are already found,
                // don't generate next level.
                if(found)
                    continue;

                // Remove one parenthesis
                for(int i = 0; i < curr.size(); i++) {

                    if(curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i) 
                                + curr.substr(i + 1);

                    if(visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            if(found)
                break;
        }

        return ans;
    }
};