class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> graph(n);

        for (auto &x : invocations) {
            graph[x[0]].push_back(x[1]);
        }

        vector<int> vis(n, 0);

        queue<int> q;
        q.push(k);
        vis[k] = 1;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int next : graph[node]) {
                if (!vis[next]) {
                    vis[next] = 1;
                    q.push(next);
                }
            }
        }

        for (auto &x : invocations) {

            int u = x[0];
            int v = x[1];

            if (!vis[u] && vis[v]) {

                vector<int> ans;

                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};