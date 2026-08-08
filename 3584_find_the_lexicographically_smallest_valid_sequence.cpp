class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> suffix(m, -1);

        int j = m - 1;

        // suffix[i] = earliest possible index for word2[i...]
        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                suffix[j] = i;
                j--;
            }
        }

        vector<int> ans;
        int pos = 0;
        bool changed = false;

        for (int i = 0; i < m; i++) {

            while (pos < n) {

                if (word1[pos] == word2[i]) {
                    ans.push_back(pos);
                    pos++;
                    break;
                }

                // Use the one allowed mismatch
                if (!changed) {

                    bool possible = false;

                    if (i == m - 1) {
                        possible = true;
                    }
                    else if (suffix[i + 1] != -1 && suffix[i + 1] > pos) {
                        possible = true;
                    }

                    if (possible) {
                        ans.push_back(pos);
                        pos++;
                        changed = true;
                        break;
                    }
                }

                pos++;
            }

            if (ans.size() != i + 1) {
                return {};
            }
        }

        return ans;
    }
};