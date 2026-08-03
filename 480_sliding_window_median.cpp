class DualHeap {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    unordered_map<int, int> delayed;

    int smallSize;
    int largeSize;
    int k;

    DualHeap(int windowSize) {
        k = windowSize;
        smallSize = 0;
        largeSize = 0;
    }

    void prune(priority_queue<int>& heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (delayed.count(num)) {
                delayed[num]--;
                if (delayed[num] == 0)
                    delayed.erase(num);
                heap.pop();
            } else {
                break;
            }
        }
    }

    void pruneMin(priority_queue<int, vector<int>, greater<int>>& heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (delayed.count(num)) {
                delayed[num]--;
                if (delayed[num] == 0)
                    delayed.erase(num);
                heap.pop();
            } else {
                break;
            }
        }
    }

    void balance() {
        if (smallSize > largeSize + 1) {
            large.push(small.top());
            small.pop();
            smallSize--;
            largeSize++;
            prune(small);
        }
        else if (smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            smallSize++;
            largeSize--;
            pruneMin(large);
        }
    }

    void insert(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
            smallSize++;
        } else {
            large.push(num);
            largeSize++;
        }
        balance();
    }

    void erase(int num) {
        delayed[num]++;

        if (num <= small.top()) {
            smallSize--;
            if (num == small.top())
                prune(small);
        } else {
            largeSize--;
            if (!large.empty() && num == large.top())
                pruneMin(large);
        }

        balance();
    }

    double getMedian() {
        if (k % 2 == 1)
            return (double)small.top();

        return ((long long)small.top() + (long long)large.top()) / 2.0;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        DualHeap dh(k);

        vector<double> ans;

        for (int i = 0; i < k; i++) {
            dh.insert(nums[i]);
        }

        ans.push_back(dh.getMedian());

        for (int i = k; i < nums.size(); i++) {
            dh.insert(nums[i]);
            dh.erase(nums[i - k]);
            ans.push_back(dh.getMedian());
        }

        return ans;
    }
};