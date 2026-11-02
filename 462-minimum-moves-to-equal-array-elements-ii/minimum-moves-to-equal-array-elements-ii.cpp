class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int target= nums[n/2];
        long long ans=0;
        for(int &ele: nums){
            ans+= abs(target-ele);
        }
        return (int)ans;
    }
};