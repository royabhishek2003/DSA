class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n= profits.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1;
        priority_queue< pair<int,int> > pq2;


        int count=0;
        int ans= w;
        for(int i=0;i<n;i++){
            pq1.push({capital[i],profits[i]});
        }
        
        while(pq1.size() >0 || pq2.size() >0){
            if(pq1.size() >0 && ans < pq1.top().first && pq2.empty()) return ans;
            while(!pq1.empty() && pq1.top().first <= ans){
                int capital= pq1.top().first;
                int profit= pq1.top().second;
                pq1.pop();
                pq2.push({profit,capital});
            }
            if(pq2.size() >0){
                ans+= pq2.top().first;
                pq2.pop();
                count++;
                if(count==k) return ans; 
            }
        }

        return ans;
    }
};