class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total = 0;

        for (int x : machines)
            total += x;

        if (total % n != 0)
            return -1;

        int avg = total / n;
        int sum = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            int diff = machines[i] - avg;
            sum += diff;

            ans = max(ans, max(abs(sum), diff));
        }

        return ans;
    }
};