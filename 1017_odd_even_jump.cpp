class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();

        vector<int> odd(n, -1);
        vector<int> even(n, -1);

        map<int, int> mp;

        for (int i = n - 1; i >= 0; i--) {
            auto it = mp.lower_bound(arr[i]);

            if (it != mp.end()) {
                odd[i] = it->second;
            }

            if (it != mp.end() && it->first == arr[i]) {
                even[i] = it->second;
            } 
            else if (it != mp.begin()) {
                --it;
                even[i] = it->second;
            }

            mp[arr[i]] = i;
        }

        vector<bool> oddGood(n, false);
        vector<bool> evenGood(n, false);

        oddGood[n - 1] = true;
        evenGood[n - 1] = true;

        int ans = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (odd[i] != -1) {
                oddGood[i] = evenGood[odd[i]];
            }

            if (even[i] != -1) {
                evenGood[i] = oddGood[even[i]];
            }

            if (oddGood[i]) {
                ans++;
            }
        }

        return ans;
    }
};