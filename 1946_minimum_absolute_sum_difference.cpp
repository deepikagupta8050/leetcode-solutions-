class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1000000007;
        int n = nums1.size();

        vector<int> sorted = nums1;
        sort(sorted.begin(), sorted.end());

        long long total = 0;
        int best = 0;

        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            total += diff;

            auto it = lower_bound(sorted.begin(), sorted.end(), nums2[i]);

            if (it != sorted.end()) {
                best = max(best, diff - abs(*it - nums2[i]));
            }

            if (it != sorted.begin()) {
                --it;
                best = max(best, diff - abs(*it - nums2[i]));
            }
        }

        return (total - best) % MOD;
    }
};