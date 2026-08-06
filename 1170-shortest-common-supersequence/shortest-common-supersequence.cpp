class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {

        // Lengths of both strings
        int m = s1.length();
        int n = s2.length();

        // t[i][j] = Length of the Shortest Common Supersequence (SCS)

        vector<vector<int>> t(m + 1, vector<int>(n + 1));

        // building the shorted commmon supersubsequence 
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {

                // If one string is empty, SCS is simply the other string.
                if (i == 0 || j == 0)
                    t[i][j] = i + j;
                else if (s1[i - 1] == s2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = 1 + min(t[i - 1][j], t[i][j - 1]);
            }
        }

        // Reconstruct the actual SCS string
        string scs = "";

        // Start from bottom-right of DP table
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                scs.push_back(s1[i - 1]);
                i--;
                j--;
            }
            else {

                // Upper cell has smaller SCS length.
                // So current character of s1 is part of answer.
                if (t[i - 1][j] < t[i][j - 1]) {
                    scs.push_back(s1[i - 1]);
                    i--;
                }
                else {
                    scs.push_back(s2[j - 1]);
                    j--;
                }
            }
        }

        // If characters remain in s1,
        while (i > 0) {
            scs.push_back(s1[i - 1]);
            i--;
        }
        // If characters remain in s2,
        while (j > 0) {
            scs.push_back(s2[j - 1]);
            j--;
        }

        reverse(scs.begin(), scs.end());

        return scs;
    }
};