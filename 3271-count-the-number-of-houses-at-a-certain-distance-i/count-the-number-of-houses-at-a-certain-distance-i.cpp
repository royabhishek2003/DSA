class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n);
        x--;
        y--;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n && j!=i ; j++){
                int direct= abs(j-i); // i->j
                int indirect1= abs(i-x)+1+abs(y-j);  // i->x->y->j
                int indirect2=abs(i-y)+1+abs(x-j); // i->y->x->j
                int mindis= min({direct,indirect1,indirect2});
                ans[mindis-1]+=2;
            }
        }
        return ans;
    }
};