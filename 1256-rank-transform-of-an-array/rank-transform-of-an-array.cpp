class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int,int> mp;
        int count=1;
        for(int &ele: temp){
            if(mp.find(ele)!=mp.end()){
                continue;
            }
            else  mp[ele]=count;
            count++;
        }
        int n= arr.size();
        vector<int> ans;
        for(int &ele: arr){
            ans.push_back(mp[ele]);
        }
        return ans;
    }
};