class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
         // approach -1 using two vectors 
        vector<int> v1,v2;
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(v1[v1.size()-1]>v2[v2.size()-1]) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        for(int ele: v2) v1.push_back(ele);

        return v1;
    }
};