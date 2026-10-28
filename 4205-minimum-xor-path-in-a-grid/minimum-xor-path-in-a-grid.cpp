class Solution {
public:
    int m,n;
    vector<vector<int>> grid;
   vector<vector<vector<int>>> memo;
    int dfs(int i, int j, int currXor) {
        if(i >= m || j >= n) return INT_MAX;

        currXor ^= grid[i][j];
        if(i == m-1 && j == n-1) {
            return currXor;
        }
        if(memo[i][j][currXor] != -1)
            return memo[i][j][currXor];

        int right = dfs(i, j+1, currXor);
        int down  = dfs(i+1, j, currXor);

        return memo[i][j][currXor] = min(right, down);
    }

    int minCost(vector<vector<int>>& gridinput) {
        grid= gridinput;
        m = grid.size();
        n = grid[0].size();
        memo.assign(m, vector<vector<int>>(n, vector<int>(1024, -1)));

        return dfs(0,0,0);
    }
};