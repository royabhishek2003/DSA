class Solution {
public:
    int n,m;
    vector<vector<int>> direction={{0,1},{1,0},{-1,0},{0,-1}};
    long long   bfs(auto &visited, auto &grid,long long sum, int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            sum+=grid[x][y];
            for(vector<int> &vec:direction){
                int newx= x + vec[0];
                int newy= y + vec[1];
                if(newx >=0 && newx < n && newy >=0 && newy<m && !visited[newx][newy] && grid[newx][newy]!=0){
                    visited[newx][newy]=true;
                    q.push({newx, newy});
                }
            }

        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans=0;
        n= grid.size();
        m= grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && !visited[i][j]){
                    long long sum= bfs(visited,grid,0,i,j);
                    if(sum%k == 0) ans+=1;
                }
            }
        }
        return ans;
        
    }
};