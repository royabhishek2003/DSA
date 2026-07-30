class Solution {
public:
    int solve(int i,int currsum,auto &nums, int target){
        if(i==nums.size()){
            if(currsum == target) return 1;
            return 0;
        }
        int plus= solve(i+1,currsum+nums[i],nums,target);
        int minus= solve(i+1,currsum-nums[i],nums,target);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(0,0,nums,target);
    }
};