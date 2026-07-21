class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char ch : s) {
            if (ch == '1') ones++;
        }

        string t = "1" + s + "1";

        vector<pair<char, int>> runs;
        for (char ch : t) {
            if (runs.empty() || runs.back().first != ch) {
                runs.push_back({ch, 1});
            } else {
                runs.back().second++;
            }
        }

        int maxGain = 0;

        for (int i = 1; i + 1 < (int)runs.size(); i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {
                
                maxGain = max(maxGain,
                              runs[i - 1].second + runs[i + 1].second);
            }
        }

        return ones + maxGain;
    }
};