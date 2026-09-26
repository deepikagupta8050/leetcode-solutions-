class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> st;

        string cur = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                nums.push(num);
                st.push(cur);
                num = 0;
                cur = "";
            }
            else if (c == ']') {
                int k = nums.top();
                nums.pop();

                string temp = st.top();
                st.pop();

                while (k--)
                    temp += cur;

                cur = temp;
            }
            else {
                cur += c;
            }
        }

        return cur;
    }
};