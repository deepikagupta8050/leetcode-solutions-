class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        int count = 0;

        while (true) {

            bool sorted = true;

            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    sorted = false;
                    break;
                }
            }

            if (sorted) {
                return count;
            }

            int pos = 0;
            int sum = nums[0] + nums[1];

            for (int i = 1; i < nums.size() - 1; i++) {

                int currSum = nums[i] + nums[i + 1];

                if (currSum < sum) {
                    sum = currSum;
                    pos = i;
                }
            }

            nums[pos] = sum;
            nums.erase(nums.begin() + pos + 1);

            count++;
        }
    }
};