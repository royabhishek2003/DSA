class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {

        int m = s1.size();
        int n = s2.size();

        // LCS DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string ans = "";
        int i = m;
        int j = n;

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans.push_back(s1[i - 1]);
                i--;
                j--;
            }

            // Move towards larger LCS
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans.push_back(s1[i - 1]);
                i--;
            }
            else {
                ans.push_back(s2[j - 1]);
                j--;
            }
        }

        // Remaining characters
        while (i > 0) {
            ans.push_back(s1[i - 1]);
            i--;
        }

        while (j > 0) {
            ans.push_back(s2[j - 1]);
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};