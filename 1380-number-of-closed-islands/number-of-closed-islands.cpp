class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{0,1},{-1,0},{0,-1},{1,0}};
    bool boundary(int i, int j){
        if(i==n-1 || j==m-1 || i==0 || j==0) return true;
        return false;
    }
    bool bfs(auto&grid, int i, int j){
        bool closed= true;
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=1;
        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            if(boundary(x,y)) {
                closed=false;
            }
            for(vector<int> &vec: dir){
                int newx= x+ vec[0];
                int newy= y+ vec[1];
                if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==0){
                    grid[newx][newy]=1;
                    q.push({newx, newy});
                }
            }
        }
        return closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n= grid.size();
        m= grid[0].size();
        int ans=0;
        // vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!boundary(i,j) && grid[i][j]==0){
                    if(bfs(grid,i,j)) 
                    ans+=1;
                }
            }
        }
        return ans;
    }
};