class Solution {
public:
    int n;
    int count=0;
    void solve(auto &nums,auto &mp,int &k,int i){
        if(i>=n){
            count+=1;
            return;
        }
        if(mp.find(nums[i]+k)==mp.end() &&  mp.find(nums[i]- k)==mp.end()){  // ham nhi le sakte nums[i] ko
            mp[nums[i]]++;
            solve(nums,mp,k,i+1);
            mp[nums[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]);
        }
        
        solve(nums,mp,k,i+1);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        n= nums.size();
        unordered_map<int,int> mp;
        solve(nums,mp,k,0);
        return count-1;
    }
};