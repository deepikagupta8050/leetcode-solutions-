class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        deque<int> dq;
        int ans = n + 1;

        for (int i = 0; i <= n; i++) {

            while (!dq.empty() && pre[i] - pre[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && pre[i] <= pre[dq.back()])
                dq.pop_back();

            dq.push_back(i);
        }

        return ans == n + 1 ? -1 : ans;
    }
};