class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        vector<int> ans;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        unordered_set<int> st;

        for (int x : nums) {
            st.insert(x);
        }

        for (int i = mn; i <= mx; i++) {
            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};