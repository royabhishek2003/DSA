class Solution {
public:
    int remainempty(vector<int>& vec){
        bool firstgroup=true;
        bool secondgroup=true;
        bool thirdgroup=true;

        for(int ele: vec){
            if(ele >=2 && ele <= 5) firstgroup=false;
            if(ele >=4 && ele <= 7) secondgroup=false;
            if(ele >=6 && ele <=9) thirdgroup=false;
        }
        if(firstgroup && secondgroup && thirdgroup) return 2;
        else if(firstgroup || secondgroup || thirdgroup) return 1;
        else return 0;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> mp;
        for(vector<int> &seat: reservedSeats){
            mp[seat[0]].push_back(seat[1]);
        }
        int result=0;
        for(auto &p: mp){
            int x= remainempty(p.second);
            result += x;
        }
        int length= mp.size();
        result += (n-length)*2;

        return result;

    }
};