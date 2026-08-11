class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n= nums.size();
        int lsp=nums[0];
        int i=1;
        while(i<n){
            if(nums[i]== nums[i-1]+1){
                lsp += nums[i];
                i++;
            }else break;
        }
        unordered_map<int,int> mp;
        for(int ele: nums) mp[ele]++;
        int x=lsp;
        while(mp.find(x)!=mp.end()){
            x+=1;
        }
        return x;
        
        
    }
};