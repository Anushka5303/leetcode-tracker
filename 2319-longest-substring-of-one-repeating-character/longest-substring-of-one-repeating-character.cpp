class Solution {
    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;
    };

    vector<Node> tree;

    Node makeNode(char c) {
        return {c, c, 1, 1, 1, 1};
    }

    Node merge(Node L, Node R) {
        Node res;

        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;
        res.len = L.len + R.len;

        res.prefix = L.prefix;
        res.suffix = R.suffix;

        res.best = max(L.best, R.best);

        if (L.rightChar == R.leftChar) {
            res.best = max(res.best,
                           L.suffix + R.prefix);

            if (L.prefix == L.len)
                res.prefix = L.len + R.prefix;

            if (R.suffix == R.len)
                res.suffix = R.len + L.suffix;
        }

        return res;
    }

    void build(int idx, int l, int r, string& s) {
        if (l == r) {
            tree[idx] = makeNode(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid, s);
        build(idx * 2 + 1, mid + 1, r, s);

        tree[idx] = merge(tree[idx * 2],
                          tree[idx * 2 + 1]);
    }

    void update(int idx, int l, int r,
                int pos, char c) {

        if (l == r) {
            tree[idx] = makeNode(c);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(idx * 2, l, mid, pos, c);
        else
            update(idx * 2 + 1, mid + 1, r, pos, c);

        tree[idx] = merge(tree[idx * 2],
                          tree[idx * 2 + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices) {

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int pos = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, pos, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};