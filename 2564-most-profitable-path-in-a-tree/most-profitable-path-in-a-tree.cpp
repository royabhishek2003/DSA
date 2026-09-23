class Solution {
public:
    unordered_map<int,int> visitedtime;
    bool isbobreached=false;
    void findvisitingtimeofbob(unordered_map<int,vector<int>> &adj, int bob, int time, vector<bool> &visited ){
        visited[bob]=true;
        visitedtime[bob]=time;
        time+=1;
        if(bob == 0){
            isbobreached=true;
            return;
        }
        for( auto & neighbour :adj[bob]){
            if(!visited[neighbour]){
                if(!isbobreached)
                findvisitingtimeofbob(adj,neighbour,time,visited);
            }
        }
        if(isbobreached==false){
            visitedtime.erase(bob);
            visited[bob]=false;
        }
    }

    int maxscore=INT_MIN;
    void traverseAlice(unordered_map<int,vector<int>> &adj, vector<int> &amount, int time, vector<bool> &visited, int currnode, int alicescore){

        visited[currnode]=true;
        if(visitedtime.find(currnode) == visitedtime.end() || time < visitedtime[currnode]){
            alicescore += amount[currnode];
        }
        else if(time == visitedtime[currnode]){
            alicescore += (amount[currnode])/2;
        }
        time+=1;
        bool isleaf=true;
        for(auto &neighbour: adj[currnode]){
            if(!visited[neighbour]){
                isleaf=false;
                traverseAlice(adj,amount,time,visited,neighbour,alicescore);
            }
        }
        if(isleaf && maxscore < alicescore){
            maxscore=alicescore;
        }
        visited[currnode]=false;
    }


    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // make a undirected Tree graph 
        unordered_map<int,vector<int>> adj;
        for(vector<int> &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        visitedtime.clear();
        int n= adj.size();
        vector<bool>visited(n,false);
        findvisitingtimeofbob(adj,bob,0,visited);
        for(int i=0;i<n;i++) visited[i]=false;
        traverseAlice(adj, amount,0,visited,0,0);

        return maxscore;

    }
};