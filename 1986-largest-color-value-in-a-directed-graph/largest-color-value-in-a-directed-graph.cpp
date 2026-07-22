class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // dp[node][c] = maximum count of color c in any path ending at node
        vector<vector<int>> dp(n, vector<int>(26, 0));

        queue<int> q;

        // Push all source nodes
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int visited = 0;
        int ans = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited++;

            // Update answer using current node
            for (int c = 0; c < 26; c++)
                ans = max(ans, dp[u][c]);

            // Traverse neighbours
            for (int v : adj[u]) {

                for (int c = 0; c < 26; c++) {

                    // If neighbour's color is c, increase count by 1
                    if (c == colors[v] - 'a')
                        dp[v][c] = max(dp[v][c], dp[u][c] + 1);
                    else
                        dp[v][c] = max(dp[v][c], dp[u][c]);
                }

                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Cycle exists
        if (visited != n)
            return -1;

        return ans;
    }
};