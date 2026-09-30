class Solution {
public:
    
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0] == ')') return false;
        int n= grid.size();
        int m= grid[0].size();
        vector<int> dx={0,1};
        vector<int> dy={1,0};
        vector<vector<vector<bool>>> visited(n,vector<vector<bool>>(m,vector<bool>(n+m+1,false)));
        queue<vector<int>> q; // {row,col,open}
        q.push({0,0,1});
        visited[0][0][1]=true;
        while(!q.empty()){
            int x= q.front()[0];
            int y= q.front()[1];
            int open= q.front()[2];
            int remainingstep= n-1-x + m-1-y;
            q.pop();
            if(x==n-1 && y==m-1 && open==0) return true;
            if(open > remainingstep) continue;
            for(int i=0;i<2;i++){
                int newx= x+dx[i];
                int newy= y+dy[i];
                if(newx >=0 && newx <n && newy>=0 && newy<m){
                    if(grid[newx][newy]=='(' && open+1 < m+n && !visited[newx][newy][open+1]){
                         q.push({newx,newy,open+1});
                         visited[newx][newy][open+1]=true;
                    }else if(grid[newx][newy]==')' && open-1>=0 && !visited[newx][newy][open-1]){
                         q.push({newx,newy,open-1});
                         visited[newx][newy][open-1]=true;
                    }
                   
                }
            }
        }
        return false;

        }
};