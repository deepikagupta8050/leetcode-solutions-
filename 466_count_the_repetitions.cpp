class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len2 = s2.size();
        vector<int> recall(len2, -1);
        vector<int> countAt(len2, 0);

        int index = 0, s2Count = 0;

        for (int s1Count = 1; s1Count <= n1; s1Count++) {
            for (char c : s1) {
                if (c == s2[index]) {
                    index++;
                    if (index == len2) {
                        index = 0;
                        s2Count++;
                    }
                }
            }

            if (recall[index] != -1) {
                int prevS1 = recall[index];
                int prevS2 = countAt[index];

                int cycleS1 = s1Count - prevS1;
                int cycleS2 = s2Count - prevS2;

                int remaining = n1 - s1Count;
                int cycles = remaining / cycleS1;

                s2Count += cycles * cycleS2;
                s1Count += cycles * cycleS1;

                for (int i = 0; i < n1 - s1Count; i++) {
                    for (char c : s1) {
                        if (c == s2[index]) {
                            index++;
                            if (index == len2) {
                                index = 0;
                                s2Count++;
                            }
                        }
                    }
                }

                return s2Count / n2;
            }

            recall[index] = s1Count;
            countAt[index] = s2Count;
        }

        return s2Count / n2;
    }
};