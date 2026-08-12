class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int> mp;
        int result=0;
        int i=0;
        int j=0;
        int maxfreq=0;
        int maxfreqele=-1;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]] > maxfreq){
                maxfreq=mp[nums[j]];
                maxfreqele=nums[j];
            }
            while(maxfreq>k){
                mp[nums[i]]--;
                if(mp.find(nums[i])==mp.end()) mp.erase(nums[i]);
                if(maxfreqele == nums[i]){
                    maxfreq=mp[nums[i]];
                }
                i++;
            }
            result=max(result,j-i+1);
            j++;
        }
        return result;
    }
};