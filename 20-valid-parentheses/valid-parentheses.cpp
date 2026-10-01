class Solution {
public:
bool isValid(string s) {
     if(s.length()%2!=0) return false;
     stack<char> st;
     for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
         if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(st.size()==0) return false;
        }
        if(s[i]==')'){
            if(st.top()=='(') st.pop();
            else return false;
        }
         if(s[i]=='}'){
            if(st.top()=='{') st.pop();
            else return false;
        }
         if(s[i]==']'){
            if(st.top()=='[') st.pop();
            else return false;
        }

        
     }
     if(st.size()!=0) return false;
        return true;
    }
};