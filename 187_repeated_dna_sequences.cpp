class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_set<string> seen;
        unordered_set<string> result;

        if (s.length() < 10) {
            return {};
        }

        for (int i = 0; i <= s.length() - 10; i++) {

            string sub = s.substr(i, 10);

            if (seen.find(sub) != seen.end()) {
                result.insert(sub);
            }
            else {
                seen.insert(sub);
            }
        }

        return vector<string>(result.begin(), result.end());
    }
};