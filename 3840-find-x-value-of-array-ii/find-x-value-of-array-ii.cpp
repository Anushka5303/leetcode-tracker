class Solution {
public:

    struct Node {
        int prod = 1;
        int cnt[5] = {};
        int l = 0, r = 0;
    };

    int k;
    vector<Node> tree;

    Node merge(Node &a, Node &b) {

        Node res;

        // Product of the whole segment
        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside left
        for (int i = 0; i < k; i++) {
            res.cnt[i] = a.cnt[i];
        }

        // Prefixes which take all of left
        // and then some prefix of right
        for (int i = 0; i < k; i++) {
            int newRem = (a.prod * i) % k;

            res.cnt[newRem] += b.cnt[i];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        tree[node].l = l;
        tree[node].r = r;

        if (l == r) {

            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );

        tree[node].l = l;
        tree[node].r = r;
    }

    void update(int node, int l, int r,
                int index, int value) {

        if (l == r) {

            int rem = value % k;

            tree[node].prod = rem;

            for (int i = 0; i < k; i++) {
                tree[node].cnt[i] = 0;
            }

            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, value);
        }
        else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );

        tree[node].l = l;
        tree[node].r = r;
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        // Completely inside
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        // Completely in left
        if (qr <= mid) {
            return query(
                node * 2,
                l,
                mid,
                ql,
                qr
            );
        }

        // Completely in right
        if (ql > mid) {
            return query(
                node * 2 + 1,
                mid + 1,
                r,
                ql,
                qr
            );
        }

        // Part in left
        // Part in right

        Node left = query(
            node * 2,
            l,
            mid,
            ql,
            qr
        );

        Node right = query(
            node * 2 + 1,
            mid + 1,
            r,
            ql,
            qr
        );

        return merge(left, right);
    }


    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        this->k = k;

        int n = nums.size();

        tree.resize(4 * n + 5);

        // Build tree
        build(nums, 1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            update(
                1,
                0,
                n - 1,
                index,
                value
            );

            // Query [start ... n-1]
            Node res = query(
                1,
                0,
                n - 1,
                start,
                n - 1
            );

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};