class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;

        // Create start and end events
        for (auto &b : buildings) {
            events.push_back({b[0], -b[2]}); // Start: negative height
            events.push_back({b[1], b[2]});  // End: positive height
        }

        // Sort events by x-coordinate
        sort(events.begin(), events.end());

        // Max heap to maintain active building heights
        priority_queue<int> pq;
        pq.push(0);

        vector<vector<int>> ans;
        int prevHeight = 0;

        for (auto &event : events) {
            int x = event.first;
            int h = event.second;

            if (h < 0) {
                // Building starts
                pq.push(-h);
            } else {
                // Building ends
                // Lazy deletion is handled using a multiset instead
            }
        }

        // Process events using a multiset for efficient deletion
        multiset<int> active;
        active.insert(0);

        ans.clear();
        prevHeight = 0;

        for (auto &event : events) {
            int x = event.first;
            int h = event.second;

            if (h < 0) {
                active.insert(-h);
            } else {
                active.erase(active.find(h));
            }

            int currHeight = *active.rbegin();

            if (currHeight != prevHeight) {
                ans.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return ans;
    }
};