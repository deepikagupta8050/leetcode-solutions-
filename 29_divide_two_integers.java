class Solution {

    public int divide(int dividend, int divisor) {

        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        boolean negative = (dividend < 0) ^ (divisor < 0);

        long num1 = Math.abs((long) dividend);
        long num2 = Math.abs((long) divisor);

        int answer = 0;

        while (num1 >= num2) {

            int count = 0;

            while (num1 >= (num2 << (count + 1))) {
                count++;
            }

            answer += (1 << count);

            num1 -= (num2 << count);
        }

        if (negative) {
            return -answer;
        }

        return answer;
    }
}