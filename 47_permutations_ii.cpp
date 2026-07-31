class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& result, vector<bool>& used) {

        if (result.size() == nums.size()) {
            ans.push_back(result);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            result.push_back(nums[i]);

            solve(nums, result, used);

            result.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> result;
        vector<bool> used(nums.size(), false);

        solve(nums, result, used);

        return ans;
    }
};