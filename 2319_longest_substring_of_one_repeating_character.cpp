class Solution {
public:
    struct Node {
        int len;
        char left, right;
        int pref, suff, best;
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        Node res;

        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;

        res.pref = a.pref;
        if (a.pref == a.len && a.right == b.left)
            res.pref += b.pref;

        res.suff = b.suff;
        if (b.suff == b.len && a.right == b.left)
            res.suff += a.suff;

        res.best = max(a.best, b.best);

        if (a.right == b.left)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {1, s[l], s[l], 1, 1, 1};
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, char c) {
        if (l == r) {
            tree[node] = {1, c, c, 1, 1, 1};
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, c);
        else
            update(node * 2 + 1, mid + 1, r, pos, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int pos = queryIndices[i];
            char c = queryCharacters[i];

            s[pos] = c;

            update(1, 0, n - 1, pos, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};