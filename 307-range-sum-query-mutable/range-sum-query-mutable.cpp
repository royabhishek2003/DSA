class NumArray {
public:
    vector<int> segmentTree;
    vector<int> nums;
    int n;
    void buildsegmentTree(int i, int low, int high){
        if(low == high){
            segmentTree[i]= nums[low];
            return;
        }
        int mid = low + (high-low)/2;
        buildsegmentTree(2*i+1,low,mid);
        buildsegmentTree(2*i+2, mid+1,high);
        segmentTree[i]= segmentTree[2*i+1] + segmentTree[2*i+2];
    }
    void updatesegmentTree(int i, int low, int high, int idx, int value){
        if(low == high){
            segmentTree[i]= value;
            return;
        }
        int mid = low + (high-low)/2;
        if(idx <= mid){
            updatesegmentTree(2*i+1, low, mid,idx,value);
        }else{
            updatesegmentTree(2*i+2, mid+1, high,idx,value);
        }
        segmentTree[i]= segmentTree[2*i+1] + segmentTree[2*i+2];
    }
    int findrangesum(int i, int low,int high, int left, int right){
        if(right< low || left > high){
            return 0;
        }
        if(low>=left && high <= right){
            return segmentTree[i];
        }
        int mid = low + (high-low)/2;
        int l = findrangesum(2*i+1,low,mid,left,right);
        int r= findrangesum(2*i+2,mid+1,high,left,right);
        return l+r;
    }
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->nums= nums;
        segmentTree.resize(4*n);
        buildsegmentTree(0,0,n-1);
    }
    
    void update(int index, int val) {
        nums[index]=val;
        updatesegmentTree(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        int sum=findrangesum(0,0,n-1,left,right);
        return sum;
    }
};
