class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            // Pack as many words as possible in the current line
            while (j < n &&
                   letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Last line or line containing only one word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += ' ';
                    }
                }

                line += string(maxWidth - line.size(), ' ');
            }
            else {
                // Fully justify the current line
                int totalSpaces = maxWidth - letters;
                int spacesPerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    line += string(spacesPerGap + (k - i < extraSpaces ? 1 : 0), ' ');
                }

                line += words[j - 1];
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};