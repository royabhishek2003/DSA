class Solution {
public:
    string strWithout3a3b(int a, int b) {
        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});

        string ans;
        while(pq.size() >0){
            auto [ele1,ch1]= pq.top();
            pq.pop();
            int n= ans.length();
            if(n>=2 && ans[n-1] == ch1 && ans[n-2] == ch1){
                auto [ele2,ch2]= pq.top();
                pq.pop();
                ans+=ch2;
                ele2--;
                if(ele2>0) pq.push({ele2,ch2});

                pq.push({ele1,ch1});
            }
            else{
                ans += ch1;
                ele1--;
                if(ele1>0) pq.push({ele1,ch1});
            }
        }
        return ans;
    }
};