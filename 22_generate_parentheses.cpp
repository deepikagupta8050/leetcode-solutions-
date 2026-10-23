class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        function<void(string, int, int)> backtrack =
            [&](string current, int open, int close) {
                if (current.size() == 2 * n) {
                    result.push_back(current);
                    return;
                }

                // Add opening bracket
                if (open < n) {
                    backtrack(current + "(", open + 1, close);
                }

                // Add closing bracket
                if (close < open) {
                    backtrack(current + ")", open, close + 1);
                }
            };

        backtrack("", 0, 0);
        return result;
    }
};