class Solution {
public:
    long long modPow(long long a, long long b) {
        long long ans = 1;
        long long mod = 1000000007;

        while (b > 0) {
            if (b & 1) {
                ans = ans * a % mod;
            }

            a = a * a % mod;
            b >>= 1;
        }

        return ans;
    }

    int maxNiceDivisors(int primeFactors) {
        long long mod = 1000000007;

        if (primeFactors <= 3) {
            return primeFactors;
        }

        int q = primeFactors / 3;
        int r = primeFactors % 3;

        if (r == 0) {
            return modPow(3, q);
        }

        if (r == 1) {
            return modPow(3, q - 1) * 4 % mod;
        }

        return modPow(3, q) * 2 % mod;
    }
};