class Solution {
public:
    int minInsertions(string s) {
        int n= s.length();
        int ans=0;
        stack<char> st;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                st.push('(');
                i+=1;
                continue;
            }
            if(i<n-1 && s[i+1] == ')'){ // pair of ))
                if(st.size()>0){
                    st.pop();
                }else{
                    ans+=1;
                }
                i+=2;
            }
            else{  // ) single closeing 
                if(st.size() >0){
                    ans+=1;
                    st.pop();
                }else{
                    ans+=2;
                }
                i+=1;
            }
        }  

        ans += st.size()*2;
        return ans;    
    }
};