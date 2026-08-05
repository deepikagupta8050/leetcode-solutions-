class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto &x : times) {
            graph[x[0]].push_back({x[1], x[2]});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > dist[node]) {
                continue;
            }

            for (auto &next : graph[node]) {

                int to = next.first;
                int wt = next.second;

                if (dist[to] > dist[node] + wt) {

                    dist[to] = dist[node] + wt;

                    pq.push({dist[to], to});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};