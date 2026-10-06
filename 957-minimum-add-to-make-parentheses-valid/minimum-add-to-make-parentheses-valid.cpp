class Solution {
public:
    int minAddToMakeValid(string s) {
       int ans=0;
       int open=0;
       for(char &ch: s){
        if(ch == ')'){
            if(open ==0)  ans+=1;
            else open-=1;
        }
        else{
            open+=1;
        }
       }
       return ans+open;
    }
};