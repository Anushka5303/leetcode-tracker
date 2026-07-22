class Solution {
    struct Group {
        int start;
        int length;
    };

    class SparseTable {
    public:
        SparseTable(const vector<int>& nums) {
            int n = nums.size();
            if (n == 0) return;

            int LOG = 32 - __builtin_clz(n);
            st.assign(LOG, vector<int>(n));

            st[0] = nums;

            for (int k = 1; k < LOG; k++) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    st[k][i] =
                        max(st[k - 1][i],
                            st[k - 1][i + (1 << (k - 1))]);
                }
            }
        }

        int query(int l, int r) const {
            if (l > r) return 0;
            int k = 31 - __builtin_clz(r - l + 1);
            return max(st[k][l],
                       st[k][r - (1 << k) + 1]);
        }

    private:
        vector<vector<int>> st;
    };

    pair<vector<Group>, vector<int>> getZeroGroups(const string& s) {
        vector<Group> groups;
        vector<int> idx(s.size(), -1);

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    groups.back().length++;
                } else {
                    groups.push_back({i, 1});
                }
            }
            idx[i] = (int)groups.size() - 1;
        }

        return {groups, idx};
    }

    vector<int> getMergeLengths(const vector<Group>& groups) {
        vector<int> res;

        for (int i = 0; i + 1 < (int)groups.size(); i++) {
            res.push_back(groups[i].length +
                          groups[i + 1].length);
        }

        return res;
    }

public:
    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries
    ) {
        int totalOnes = 0;
        for (char c : s)
            totalOnes += (c == '1');

        auto [zeroGroups, zeroIdx] = getZeroGroups(s);

        if (zeroGroups.empty()) {
            return vector<int>(queries.size(), totalOnes);
        }

        SparseTable st(getMergeLengths(zeroGroups));

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int best = totalOnes;

            int left = -1;
            if (zeroIdx[l] != -1) {
                left =
                    zeroGroups[zeroIdx[l]].length -
                    (l - zeroGroups[zeroIdx[l]].start);
            }

            int right = -1;
            if (zeroIdx[r] != -1) {
                right =
                    r - zeroGroups[zeroIdx[r]].start + 1;
            }

            int startAdj = zeroIdx[l] + 1;
            int endAdj =
                (s[r] == '1')
                    ? zeroIdx[r]
                    : zeroIdx[r] - 1;

            if (s[l] == '0' &&
                s[r] == '0' &&
                zeroIdx[l] + 1 == zeroIdx[r]) {
                best = max(best, totalOnes + left + right);
            } else if (startAdj <= endAdj - 1) {
                best = max(best,
                           totalOnes +
                               st.query(startAdj,
                                        endAdj - 1));
            }

            if (s[l] == '0') {
                int nxt = zeroIdx[l] + 1;
                int last =
                    (s[r] == '1')
                        ? zeroIdx[r]
                        : zeroIdx[r] - 1;

                if (nxt <= last &&
                    nxt < (int)zeroGroups.size()) {
                    best = max(
                        best,
                        totalOnes +
                            left +
                            zeroGroups[nxt].length
                    );
                }
            }

            if (s[r] == '0') {
                int prv = zeroIdx[r] - 1;
                if (zeroIdx[l] < prv &&
                    prv >= 0) {
                    best = max(
                        best,
                        totalOnes +
                            right +
                            zeroGroups[prv].length
                    );
                }
            }

            ans.push_back(best);
        }

        return ans;
    }
};