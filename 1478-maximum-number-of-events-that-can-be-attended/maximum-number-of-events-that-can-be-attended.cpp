class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // har din ek event attend kar sakte ho toh kitne event attend kar payenge ham agar jis day pe hai us day se pehle hi koi event khtam ho gya toh usko ham attend nahi kar payenge 

        int n= events.size();
        sort(begin(events),end(events));
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int i=0;
        int day = events[0][0];
        int attended=0;
        while(i<n || !pq.empty()){
            while(i<n && events[i][0] == day){
                pq.push({events[i][1],events[i][0]});
                i++;
            }
            while (!pq.empty() && pq.top().first < day)
                pq.pop();
            if(!pq.empty()){
                pq.pop();
                attended++;
            } 
            day++;
        }

        return attended;
    }
};