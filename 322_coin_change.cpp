class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& coins, int amount) {

        if (amount == 0)
            return 0;

        if (amount < 0)
            return 1000000;

        if (dp[amount] != -2)
            return dp[amount];

        int ans = 1000000;

        for (int coin : coins) {

            int result = solve(coins, amount - coin);

            ans = min(ans, 1 + result);
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {

        dp.assign(amount + 1, -2);

        int ans = solve(coins, amount);

        if (ans >= 1000000)
            return -1;

        return ans;
    }
};