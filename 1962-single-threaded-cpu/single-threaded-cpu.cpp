class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pp, vector<pp>, greater<pp> > pq1; // {st,idx,dur}
        priority_queue<pp, vector<pp>, greater<pp> > pq2; // {dur,idx,st}

        int n= tasks.size();
        for(int i=0;i<n;i++){
            pq1.push({tasks[i][0],{i,tasks[i][1]}});
        }

        vector<int> ans;
        long long t= pq1.top().first;
        while(pq1.size() >0 || pq2.size() > 0){
            if (pq2.empty() && !pq1.empty() && t < pq1.top().first)
            t = pq1.top().first;
            while(!pq1.empty() && pq1.top().first <= t){
                int st= pq1.top().first;
                int idx= pq1.top().second.first;
                int dur= pq1.top().second.second;
                pq2.push({dur,{idx,st}});
                pq1.pop();
            }
            if(!pq2.empty()){
            t+= pq2.top().first;
            ans.push_back(pq2.top().second.first);
            pq2.pop();
           }
        }
        return ans;
    }
};