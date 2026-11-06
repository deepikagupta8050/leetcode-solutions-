class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min heap: {value, list index, element index}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        int maxVal = INT_MIN;

        // Initialize heap with first element of every list
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            maxVal = max(maxVal, nums[i][0]);
        }

        int rangeStart = 0;
        int rangeEnd = INT_MAX;

        while (pq.size() == nums.size()) {
            auto curr = pq.top();
            pq.pop();

            int minVal = curr[0];
            int listIdx = curr[1];
            int elemIdx = curr[2];

            // Update the smallest range
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // Move to the next element in the same list
            if (elemIdx + 1 == nums[listIdx].size()) {
                break;
            }

            int nextVal = nums[listIdx][elemIdx + 1];

            pq.push({nextVal, listIdx, elemIdx + 1});

            maxVal = max(maxVal, nextVal);
        }

        return {rangeStart, rangeEnd};
    }
};