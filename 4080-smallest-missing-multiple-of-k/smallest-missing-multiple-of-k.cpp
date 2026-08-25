class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mp;
        for(int ele: nums){
            mp.insert(ele);
        }

        int ele= k;
        while(mp.find(ele)!=mp.end()){
            ele +=k;
        }
        return ele;
        
        
    }
};