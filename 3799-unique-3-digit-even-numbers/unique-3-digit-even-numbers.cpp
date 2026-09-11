class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10);

        for (int d : digits)
            freq[d]++;

        int ans = 0;

        for (int a = 1; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 8; c += 2) {

                    vector<int> need(10);
                    need[a]++;
                    need[b]++;
                    need[c]++;

                    bool ok = true;

                    for (int d = 0; d <= 9; d++) {
                        if (need[d] > freq[d]) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok)
                        ans++;
                }
            }
        }

        return ans;
    }
};