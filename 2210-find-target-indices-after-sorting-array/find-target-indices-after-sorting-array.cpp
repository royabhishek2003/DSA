class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n= nums.size();
        int smaller=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i] < target) smaller++;
            if(nums[i]==target) count+=1;
        }
        vector<int> ans;
        for(int i=1;i<=count;i++){
            ans.push_back(smaller);
            smaller+=1;
        }
        return ans;
    }
};