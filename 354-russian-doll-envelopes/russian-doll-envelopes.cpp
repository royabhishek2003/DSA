class Solution {
public:
    int size;
    int solve(int i,auto & envelops){
        if(i>=size) return 0;
    
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n= envelopes.size();
        size=n;
        auto mycomp= [](vector<int> &v1, vector<int> &v2){
                if(v1[0] != v2[0]){
                    return v1[0]< v2[0];
                }else return v1[1]>v2[1];
               
        };
        sort(envelopes.begin(), envelopes.end(),mycomp);

        // after sorting we just need to find the LIS on the heights 

        vector<int> lis;

        for (auto &env : envelopes) {

            int h = env[1];

            // Find first element >= h
            auto it = lower_bound(lis.begin(), lis.end(), h);

            if (it == lis.end()) {
                // h is bigger than everything
                lis.push_back(h);
            }
            else {
                // Replace the current value
                *it = h;
            }
        }

        return lis.size();



    }
};