
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        int m = logs.size();
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // Store query and its original index
        vector<pair<int,int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        int i = 0, j = 0;

        set<int> s;
        vector<int> freq(n + 1, 0);
        vector<int> ans(queries.size());

        for (auto [query, idx] : q) {

            int st = query - x;
            int end = query;

            // Add logs inside the right boundary
            while (j < m && logs[j][1] <= end) {
                int id = logs[j][0];

                freq[id]++;

                if (freq[id] == 1)
                    s.insert(id);

                j++;
            }

            // Remove logs outside the left boundary
            while (i < j && logs[i][1] < st) {
                int id = logs[i][0];

                freq[id]--;

                if (freq[id] == 0)
                    s.erase(id);

                i++;
            }

            ans[idx] = n - s.size();
        }

        return ans;
    }
};
