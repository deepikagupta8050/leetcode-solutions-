class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // Add 1 at both ends
        vector<int> arr(n + 2, 1);

        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }

        // dp[i][j] = maximum coins from balloons i to j
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Length of the interval
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;

                // Choose the last balloon to burst
                for (int k = i; k <= j; k++) {
                    int coins = arr[i - 1] * arr[k] * arr[j + 1]
                              + dp[i][k - 1]
                              + dp[k + 1][j];

                    dp[i][j] = max(dp[i][j], coins);
                }
            }
        }

        return dp[1][n];
    }
};