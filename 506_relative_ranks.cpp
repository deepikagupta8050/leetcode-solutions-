class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        int n = score.size();

        vector<int> arr = score;
        sort(arr.begin(), arr.end(), greater<int>());

        unordered_map<int, string> mp;

        for (int i = 0; i < n; i++) {

            if (i == 0)
                mp[arr[i]] = "Gold Medal";
            else if (i == 1)
                mp[arr[i]] = "Silver Medal";
            else if (i == 2)
                mp[arr[i]] = "Bronze Medal";
            else
                mp[arr[i]] = to_string(i + 1);
        }

        vector<string> ans;

        for (int i = 0; i < n; i++) {
            ans.push_back(mp[score[i]]);
        }

        return ans;
    }
};