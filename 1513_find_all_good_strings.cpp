class Solution {
public:
    const int MOD = 1000000007;

    int n, m;
    string s1, s2, evil;
    int lps[55];
    int dp[505][55][2][2];

    void buildLPS() {
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && evil[i] != evil[j])
                j = lps[j - 1];

            if (evil[i] == evil[j])
                j++;

            lps[i] = j;
        }
    }

    int go(int pos, int match, int small, int big) {
        if (match == m)
            return 0;

        if (pos == n)
            return 1;

        int &ans = dp[pos][match][small][big];

        if (ans != -1)
            return ans;

        ans = 0;

        char lo = small ? 'a' : s1[pos];
        char hi = big ? 'z' : s2[pos];

        for (char c = lo; c <= hi; c++) {
            int j = match;

            while (j > 0 && evil[j] != c)
                j = lps[j - 1];

            if (evil[j] == c)
                j++;

            if (j == m)
                continue;

            int ns = small || (c > s1[pos]);
            int nb = big || (c < s2[pos]);

            ans = (ans + go(pos + 1, j, ns, nb)) % MOD;
        }

        return ans;
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        this->n = n;
        this->s1 = s1;
        this->s2 = s2;
        this->evil = evil;

        m = evil.size();

        memset(lps, 0, sizeof(lps));
        memset(dp, -1, sizeof(dp));

        buildLPS();

        return go(0, 0, 0, 0);
    }
};