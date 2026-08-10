class Solution {
public:
    vector<string> ans;

    void solve(string &s, int pos, int parts, string ip) {

        if (parts == 4) {
            if (pos == s.size()) {
                ip.pop_back();
                ans.push_back(ip);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {

            if (pos + len > s.size()) {
                break;
            }

            string part = s.substr(pos, len);

            // Leading zero
            if (part.size() > 1 && part[0] == '0') {
                continue;
            }

            // Value greater than 255
            if (stoi(part) > 255) {
                continue;
            }

            solve(s, pos + len, parts + 1, ip + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {

        solve(s, 0, 0, "");

        return ans;
    }
};