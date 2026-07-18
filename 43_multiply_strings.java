class Solution {

    public String multiply(String num1, String num2) {

        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }

        int[] ans = new int[num1.length() + num2.length()];

        for (int i = num1.length() - 1; i >= 0; i--) {

            for (int j = num2.length() - 1; j >= 0; j--) {

                int a = num1.charAt(i) - '0';
                int b = num2.charAt(j) - '0';

                int mul = a * b;

                int p1 = i + j;
                int p2 = i + j + 1;

                int sum = mul + ans[p2];

                ans[p2] = sum % 10;
                ans[p1] += sum / 10;
            }
        }

        StringBuilder res = new StringBuilder();

        for (int num : ans) {

            if (res.length() == 0 && num == 0) {
                continue;
            }

            res.append(num);
        }

        return res.toString();
    }
}