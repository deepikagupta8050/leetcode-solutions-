class Solution {
public:

    vector<int> getMax(vector<int>& nums, int k) {

        vector<int> ans;
        int remove = nums.size() - k;

        for (int num : nums) {

            while (!ans.empty() && remove > 0 && ans.back() < num) {
                ans.pop_back();
                remove--;
            }

            ans.push_back(num);
        }

        ans.resize(k);

        return ans;
    }

    bool bigger(vector<int>& a, int i, vector<int>& b, int j) {

        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }

        if (j == b.size()) return true;
        if (i == a.size()) return false;

        return a[i] > b[j];
    }

    vector<int> join(vector<int>& a, vector<int>& b) {

        vector<int> ans;

        int i = 0;
        int j = 0;

        while (i < a.size() || j < b.size()) {

            if (bigger(a, i, b, j))
                ans.push_back(a[i++]);
            else
                ans.push_back(b[j++]);
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> ans;

        int low = max(0, k - (int)nums2.size());
        int high = min(k, (int)nums1.size());

        for (int take = low; take <= high; take++) {

            vector<int> first = getMax(nums1, take);
            vector<int> second = getMax(nums2, k - take);

            vector<int> cur = join(first, second);

            if (bigger(cur, 0, ans, 0))
                ans = cur;
        }

        return ans;
    }
};