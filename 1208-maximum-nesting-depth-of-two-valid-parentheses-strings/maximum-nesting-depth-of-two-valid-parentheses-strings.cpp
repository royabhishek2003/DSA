class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int pendingOpen=0;
        int maxDepth=0;
        int depth=0;
        for(char &ch: seq){
            if(ch=='(') depth+=1;
            else depth-=1;
            maxDepth= max(maxDepth,depth);
        }
        vector<int> ans;
        for(char &ch: seq){
            if(ch =='('){
                if(depth < (maxDepth/2)){
                    ans.push_back(1);
                    depth+=1;
                }
                else{
                    ans.push_back(0);
                    pendingOpen+=1;
                }
            }else{
                if(pendingOpen!=0){
                    ans.push_back(0);
                    pendingOpen-=1;
                }
                else{
                    ans.push_back(1);
                    depth-=1;
                }
            }
        }
        return ans;
    }
};