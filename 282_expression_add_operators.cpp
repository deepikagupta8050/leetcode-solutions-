class Solution {
public:
    vector<string> ans;

    void solve(string &num, int target, int pos, long long value,
               long long prev, string exp) {
        if (pos == num.size()) {
            if (value == target)
                ans.push_back(exp);
            return;
        }

        long long cur = 0;

        for (int i = pos; i < num.size(); i++) {
            if (i > pos && num[pos] == '0')
                break;

            cur = cur * 10 + (num[i] - '0');
            string part = num.substr(pos, i - pos + 1);

            if (pos == 0) {
                solve(num, target, i + 1, cur, cur, part);
            } else {
                solve(num, target, i + 1,
                      value + cur, cur, exp + "+" + part);

                solve(num, target, i + 1,
                      value - cur, -cur, exp + "-" + part);

                solve(num, target, i + 1,
                      value - prev + prev * cur,
                      prev * cur, exp + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, 0, 0, "");
        return ans;
    }
};