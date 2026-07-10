class Solution {
public:
    vector<int> segTree;
    void buildsegTree(int i, int low, int high, vector<int> &heights){
        if(low == high){
            segTree[i]= low;
            return;
        }
        int mid = low + (high-low)/2;
        buildsegTree(2*i+1, low,mid,heights);
        buildsegTree(2*i+2,mid+1,high,heights);
        int leftmaxidx= segTree[2*i+1];
        int rightmaxidx= segTree[2*i+2];
        if(heights[leftmaxidx] > heights[rightmaxidx]){
            segTree[i]= leftmaxidx;
        }else{
            segTree[i]= rightmaxidx;
        }
    }

    int searchmaxindex(int i, int low, int high, int left, int right, vector<int> &heights){
        // completly outside 
        if(right < low || left > high) return -1;
        // completly inside 
        if(low >= left && high <= right){
            return segTree[i];
        }
        int mid = low + (high-low)/2;
        int leftmaxidx= searchmaxindex(2*i+1,low,mid,left,right,heights);
        int rightmaxidx = searchmaxindex(2*i+2, mid+1,high,left, right,heights);
        if(leftmaxidx == -1) return rightmaxidx;
        if(rightmaxidx == -1) return leftmaxidx;
        if(heights[leftmaxidx] > heights[rightmaxidx]){
            return leftmaxidx;
        }else{
            return rightmaxidx;
        }

    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // Binary search in range maximum index queries 
        int n= heights.size();
        segTree.resize(4*n);
        buildsegTree(0,0,n-1,heights);
        vector<int> ans;
        for(vector<int> &query: queries){
            int st= query[0];
            int end= query[1];
            if(st > end) swap(st,end);
            if(st == end) {  // dono ek hi buiding pe khade hai 
                ans.push_back(st);
                continue;
            }
            if(heights[end] > heights[st]){  // baad me jo khada hai uska buiding bada hai toh pehle wala waha ja sakta hai 
                ans.push_back(end);
                continue;
            }
           
            int low = end+1;
            int high = n-1;
            int result = -1;
            while(low <= high){
                int mid= low + (high-low)/2;
                int ansinleft= searchmaxindex(0,0,n-1,low,mid,heights);
                if(heights[ansinleft] > heights[st] && heights[ansinleft] > heights[end] ){
                    result= ansinleft;
                    high = mid -1;
                }else{
                    low = mid+1;
                }
            }
            ans.push_back(result);
        }

        return ans;


    }
};