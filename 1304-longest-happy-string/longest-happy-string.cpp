class Solution {
public:
    string longestDiverseString(int a, int b, int c) { 
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans;
        while(!pq.empty()){
            auto [ele1,ch1]=pq.top();
            pq.pop();
            int n= ans.length();
            // means ch1 dalne pe 3 consecutive character ban jayega 
            if(n>=2 && ans[n-1]==ch1 && ans[n-2]==ch1){
                if(pq.size() ==0) return ans;
                auto [ele2,ch2]=pq.top();
                pq.pop();
                ans += ch2;
                ele2--;
                if(ele2>0) pq.push({ele2,ch2});
                pq.push({ele1,ch1});
            } 
            else{  // means ham le sakte hai top wale ko 
                ans += ch1;
                ele1 --;
                if(ele1>0) pq.push({ele1,ch1});
            }
        }

        return ans;
    }
};