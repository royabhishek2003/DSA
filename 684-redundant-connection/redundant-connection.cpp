class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]= find(parent[x]);
    }

    void dounion(int x, int y){
        int parent_x= find(x);
        int parent_y= find(y);

        if(parent_x  == parent_y) return;
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y]= parent_x;
        }
        else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x]= parent_y;
        }else{
            parent[parent_x]= parent_y;
            rank[parent_y]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n= edges.size();
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        rank.resize(n+1,1);

        for(vector<int> &edge: edges){
            int u= edge[0];
            int v= edge[1];
            int parent_u= find(u);
            int parent_v= find(v);
            if(parent_u == parent_v)  return {u,v};
            dounion(parent_u, parent_v);
        }
        return {};
    }
};