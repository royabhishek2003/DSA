class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(100);
        for(char &ch: tasks){
            freq[(int)ch]++;
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<100;i++){
            if(freq[i]!=0){
                pq.push({freq[i],(char)i});
            }
        }
        unordered_map<char,int> mp;
        int day =1;
        while(!pq.empty()){
            queue<pair<int,int>> q;
            while(!pq.empty() && mp.count(pq.top().second) && day <= mp[pq.top().second] + n){
                int count=pq.top().first;
                int character= pq.top().second;
                pq.pop();
                q.push({count,character});
            }
            if(!pq.empty()){
                int count=pq.top().first;
                int character= pq.top().second;
                pq.pop();
                count--;
                mp[character] = day;
                if(count) pq.push({count,character});  
            } 
            while(!q.empty()){
                    pq.push({q.front().first, q.front().second});
                    q.pop();
            }         
            day++;
        }   

        return day -1;
        
    }
};