class Solution {
public:
    int calculate(string s) {
       stack<int> st;
       long long num=0;
       int result=0;
       int sign=1;
       int ans=0;
       for(char &ch: s){
            if(ch-'0' >=0 && ch -'0'<=9){ // digit 
                num= num*10 + ch -'0';
            }
            else if(ch == '+' || ch =='-'){
                result = result + sign*num;
                num=0;
                sign= (ch == '+')? 1: -1;
            }
            else if(ch == '('){
                st.push(result);
                st.push(sign);
                result=0;
                num=0;
                sign=1;
            }
            else if(ch == ')'){
                result = result + sign*num;
                num=0;
                result*=st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
       }
       return result+ sign*num;
    }
};