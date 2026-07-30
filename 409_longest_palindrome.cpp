class Solution {
public:
    int longestPalindrome(string s) {

        int count[128] = {0};

        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }

        int ans = 0;
        bool odd = false;

        for (int i = 0; i < 128; i++) {

            if (count[i] % 2 == 0) {
                ans += count[i];
            }
            else {
                ans += count[i] - 1;
                odd = true;
            }
        }

        if (odd) {
            ans++;
        }

        return ans;
    }
};