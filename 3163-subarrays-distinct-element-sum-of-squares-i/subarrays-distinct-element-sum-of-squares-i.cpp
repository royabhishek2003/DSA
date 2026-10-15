class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> s;
        int ans=0;
        for(int i=0;i<n;i++){
            s.clear();
            for(int j=i;j<n;j++){
                s.insert(nums[j]);
                int distint= s.size();
                ans+= distint*distint;
            }
            
        }
        return ans;
    }
};