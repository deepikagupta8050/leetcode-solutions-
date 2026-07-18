class Solution {

    public int romanToInt(String s) {

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            int curr = value(s.charAt(i));

            if (i < s.length() - 1) {

                int next = value(s.charAt(i + 1));

                if (curr < next) {
                    ans -= curr;
                } else {
                    ans += curr;
                }

            } else {

                ans += curr;
            }
        }

        return ans;
    }

    public int value(char ch) {

        if (ch == 'I') return 1;
        if (ch == 'V') return 5;
        if (ch == 'X') return 10;
        if (ch == 'L') return 50;
        if (ch == 'C') return 100;
        if (ch == 'D') return 500;

        return 1000;
    }
}