
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m= logs.size();
        sort(logs.begin(), logs.end(), [&](vector<int> &a, vector<int> &b){
            return a[1]<b[1];
        });
        vector<pair<int,int>>q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(), q.end());
        vector<int> ans(queries.size());
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        for(auto &query: q){
            int id= query.second;
            int st= query.first -x;
            int end= query.first;
            while(j<m && logs[j][1] <= end){
                mp[logs[j][0]]++;
                j++;
            }
            while(i<j && logs[i][1] < st){
                int server = logs[i][0];
                mp[server]--;
                if(mp[server] == 0)  mp.erase(server);
                i++;
            }
            ans[id]=n-mp.size(); 
        }

        return ans;

    }
};
