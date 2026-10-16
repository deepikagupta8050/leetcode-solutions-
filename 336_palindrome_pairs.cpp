class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;

        int n = words.size();

        // Store reversed words in the map
        for (int i = 0; i < n; i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            string word = words[i];
            int len = word.length();

            for (int j = 0; j <= len; j++) {

                // Case 1: Prefix is palindrome
                // Find matching word for the remaining suffix
                if (isPalindrome(word, 0, j - 1)) {
                    string suffix = word.substr(j);
                    auto it = mp.find(suffix);

                    if (it != mp.end() && it->second != i) {
                        ans.push_back({it->second, i});
                    }
                }

                // Case 2: Suffix is palindrome
                // Find matching word for the remaining prefix
                if (j != len &&
                    isPalindrome(word, j, len - 1)) {

                    string prefix = word.substr(0, j);
                    auto it = mp.find(prefix);

                    if (it != mp.end() && it->second != i) {
                        ans.push_back({i, it->second});
                    }
                }
            }
        }

        return ans;
    }
};