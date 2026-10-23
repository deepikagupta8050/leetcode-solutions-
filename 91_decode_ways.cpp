class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        if (s[0] != '0') {
            dp[1] = 1;
        }

        for (int i = 2; i <= n; i++) {
            // Single digit: 1 to 9
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // Two digits: 10 to 26
            int twoDigit = (s[i - 2] - '0') * 10
                         + (s[i - 1] - '0');

            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};