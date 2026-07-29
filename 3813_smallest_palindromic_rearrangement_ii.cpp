class Solution {
public:
    static const long long LIM = 1000001;

    long long combLimited(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= LIM) return LIM;
        }
        return ans;
    }

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long long res = 1;
        int rem = total;

        for (int x : cnt) {
            if (x == 0) continue;
            res *= combLimited(rem, x);
            if (res >= LIM) return LIM;
            rem -= x;
        }

        return min(res, LIM);
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2) mid = char('a' + i);
        }

        if (countWays(half) < k) return "";

        string left;
        int len = s.size() / 2;

        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (s.size() & 1)
            return left + string(1, mid) + right;

        return left + right;
    }
};