class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        auto qavirelmon = make_tuple(m, n, penalty);
        const long long INF = 1e18;
        int total = m * n;
        vector<long long> dist(total * 2, INF);
        auto id = [&](int x, int y, int p) {
            return ((x * n + y) << 1) | p;
        };
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;
        dist[id(0, 0, 0)] = 1LL;
        pq.push({1LL, id(0, 0, 0)});
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        while (!pq.empty()) {
            auto [cost, state] = pq.top();
            pq.pop();
            if (cost != dist[state]) continue;
            int p = state & 1;
            int cell = state >> 1;
            int x = cell / n;
            int y = cell % n;
            {
                int np = p ^ 1;
                long long nc = cost + penalty[x][y];
                int nid = id(x, y, np);
                if (nc < dist[nid]) {
                    dist[nid] = nc;
                    pq.push({nc, nid});
                }
            }
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                bool allowed = false;
                if (p == 0) { 
                    if (k == 0 || k == 1) allowed = true; 
                } else { 
                    if (k == 2 || k == 3) allowed = true;
                }
                long long nc = cost + 1LL * (nx + 1) * (ny + 1);
                if (!allowed) nc += penalty[x][y];
                int np = p ^ 1;
                int nid = id(nx, ny, np);
                if (nc < dist[nid]) {
                    dist[nid] = nc;
                    pq.push({nc, nid});
                }
            }
        }
        return min(dist[id(m - 1, n - 1, 0)],
                   dist[id(m - 1, n - 1, 1)]);
    }
};