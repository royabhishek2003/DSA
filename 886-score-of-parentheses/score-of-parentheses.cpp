class Solution {
public:
    int scoreOfParentheses(string s) {
        // aprroach -1 
        // int n= s.length();
        // int score=0;
        // vector<int> st;
        // for(int i=0;i<n;i++){
        //     if(s[i]=='('){
        //         st.push_back(score);
        //         score=0;
        //     }else{
        //         if(i>0 && s[i-1]=='('){
        //             score += st.back() + 1;
        //         }else{
        //             score = st.back() + 2*score;
        //         }
        //         st.pop_back();
        //     }
        // }
        // return score;

        // approach -2 using constant space 
        int n= s.length();
        int ans=0;
        int open=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open+=1;
            }else{
                if(i>0 && s[i-1]=='('){
                    open-=1;
                    ans += 1<<open;
                }else{
                    open -= 1;
                }
            }
        }
        return ans;
    }
};