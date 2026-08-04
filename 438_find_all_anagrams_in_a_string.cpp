class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.size() > s.size()) {
            return ans;
        }

        vector<int> countP(26, 0);
        vector<int> countS(26, 0);

        for (int i = 0; i < p.size(); i++) {
            countP[p[i] - 'a']++;
            countS[s[i] - 'a']++;
        }

        if (countP == countS) {
            ans.push_back(0);
        }

        for (int i = p.size(); i < s.size(); i++) {

            countS[s[i] - 'a']++;
            countS[s[i - p.size()] - 'a']--;

            if (countP == countS) {
                ans.push_back(i - p.size() + 1);
            }
        }

        return ans;
    }
};