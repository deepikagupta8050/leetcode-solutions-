class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1;
        unordered_set<int> ans;

        for (int num : nums1) {
            set1.insert(num);
        }

        for (int num : nums2) {

            if (set1.count(num)) {
                ans.insert(num);
            }
        }

        vector<int> result;

        for (int num : ans) {
            result.push_back(num);
        }

        return result;
    }
};