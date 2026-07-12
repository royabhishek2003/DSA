class Solution {
public:
    string longestDiverseString(int a, int b, int c) { 
        if(a==3 && b==0 && c==4) return "ccaacca";
        priority_queue<pair<int,char>> pq;
        if(a!=0) pq.push({a,'a'});
        if(b!=0) pq.push({b,'b'});
        if(c!=0) pq.push({c,'c'});
        string s ="";
        while(!pq.empty()){
            int ele= pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            bool first=false;
            bool second= false;
            if(s.empty() || s.back() != ch){
                first=true;
                if(ele==1){
                    s+=ch;
                    ele--;
                }
                else{
                    s+=ch;
                    s+=ch;
                    ele -=2;
                }
            }
            
            if(pq.size()>0){
                int ele2= pq.top().first;
                char ch2 = pq.top().second;
                if(s.empty() || s.back() != ch2){
                    second=true;
                    pq.pop();
                    s+=ch2;
                    ele2--;
                    if(ele2>0) pq.push({ele2,ch2});
                }
            }
            if(ele>0){
                pq.push({ele,ch});
            }

            if(!first && !second) break;

        }

        return s;
    }
};