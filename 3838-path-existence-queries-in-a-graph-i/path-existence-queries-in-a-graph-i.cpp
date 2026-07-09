class Solution {
public:
    
    vector<bool>segmentTree;
    void buildsegmentTree(long long i, long long low, long long high,vector<int> &nums, int maxdiff ){
        if(low == high){
            segmentTree[i]=true;
            return;
        }
        int mid = low +(high-low)/2;
        buildsegmentTree(2*i+1, low,mid,nums,maxdiff);
        buildsegmentTree(2*i+2, mid+1,high, nums,maxdiff);
        int leftchild= 2*i+1;
        int rightchild= 2*i+2;
        segmentTree[i]= segmentTree[leftchild]
                        && segmentTree[rightchild]
                        && nums[mid+1]- nums[mid] <= maxdiff ;


    }
    bool isedge(int left, int right, long long i, long long low, long long  high, vector<int> &nums,int maxdiff){
        // completly outside
        if(right < low || left > high){
            return true;
        }
        if(low >= left && high <= right){
            return segmentTree[i];
        }
        int mid = low +(high-low)/2;
        bool l = isedge(left,right,2*i+1, low,mid,nums,maxdiff);
        bool r = isedge(left,right,2*i+2,mid+1,high,nums,maxdiff);
        bool ans = l && r;
        if (left <= mid && right >= mid + 1)
            ans &= (nums[mid + 1] - nums[mid] <= maxdiff);

        return ans;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        segmentTree.resize(4*n);
        buildsegmentTree(0,0,n-1,nums,maxDiff);

        vector<bool> ans;
        for(vector<int> &q: queries){
            int left = min(q[0], q[1]);
            int right = max(q[0], q[1]);
            ans.push_back(isedge(left, right, 0, 0, n - 1, nums, maxDiff));
        }

        return ans;
    }
};