class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n= tasks.size();
        unordered_map<int,int> mp;
        for(int &task: tasks) mp[task]++;
        
        int count=0;
        while(mp.size()>0){
            auto it = mp.begin();
            if(it->second >4 || it->second==3){
                mp[it->first]-=3;
                count++;
            }else if(it->second ==1){
                return -1;
            }
            else if(it->second ==2 || it->second==4){
                mp[it->first]-=2;
                count++;
            }
            if(mp[it->first]==0) mp.erase(it->first);
        }
        return count;
        
    }
};