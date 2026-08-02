class Solution {
public:
    bool valid(string s) {
        int count = 0;

        for (char ch : s) {
            if (ch == '(')
                count++;
            else if (ch == ')') {
                if (count == 0)
                    return false;
                count--;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;
        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);

        bool found = false;

        while (!q.empty()) {

            string cur = q.front();
            q.pop();

            if (valid(cur)) {
                ans.push_back(cur);
                found = true;
            }

            if (found)
                continue;

            for (int i = 0; i < cur.size(); i++) {

                if (cur[i] != '(' && cur[i] != ')')
                    continue;

                string next = cur.substr(0, i) + cur.substr(i + 1);

                if (vis.find(next) == vis.end()) {
                    vis.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};