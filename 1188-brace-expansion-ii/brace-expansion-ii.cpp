class Solution {
public:

    // Parse concatenation
    set<string> parseConcat(string &s, int &i) {

        set<string> result;
        result.insert("");

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> cur;

            if (s[i] == '{') {
                i++; // skip '{'

                cur = parseUnion(s, i);

                i++; // skip '}'
            }
            else {
                // single character
                string ch(1, s[i]);
                cur.insert(ch);
                i++;
            }

            // Cartesian product = concatenation
            set<string> temp;

            for (string a : result) {
                for (string b : cur) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }


    // Parse union
    set<string> parseUnion(string &s, int &i) {

        set<string> result;

        while (i < s.size() && s[i] != '}') {

            set<string> part = parseConcat(s, i);

            result.insert(part.begin(), part.end());

            if (i < s.size() && s[i] == ',') {
                i++; // skip comma
            }
        }

        return result;
    }


    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parseUnion(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};