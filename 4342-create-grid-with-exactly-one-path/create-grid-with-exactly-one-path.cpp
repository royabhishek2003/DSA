class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string str="";
        for(int i=0;i<n;i++){
            str+=" ";
        }
        vector<string> ans(m,str);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // leave first col
                if(j==0 || i==m-1){
                    ans[i][j]='.'; 
                }else ans[i][j]='#';
            }
        }
        return ans;
    }
};