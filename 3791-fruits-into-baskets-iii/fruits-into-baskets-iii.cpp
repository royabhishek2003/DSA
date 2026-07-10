class Solution {
public:
    vector<int> segmentTree;
    void buildsegmentTree(int i, int low, int high, vector<int> &baskets){
        if(low == high){
            segmentTree[i]=baskets[low];
            return;
        }
        int mid = low +(high-low)/2;
        buildsegmentTree(2*i+1,low,mid,baskets);
        buildsegmentTree(2*i+2,mid+1,high,baskets);
        segmentTree[i]= max(segmentTree[2*i+1], segmentTree[2*i+2]);
    }

    bool searchquery(int fruit, int i, int low, int high){
        if(segmentTree[i] < fruit) return false;
        if(low == high){
            segmentTree[i]=-1;
            return true;
        }
        int mid = low +(high-low)/2;

        bool ans = searchquery(fruit,2*i+1,low,mid);
        if(!ans){
            ans= searchquery(fruit,2*i+2,mid+1,high);
        }
        segmentTree[i]= max(segmentTree[2*i+1], segmentTree[2*i+2]);
        return true;
    }


    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // using segment Tree 
        int n = fruits.size();
        segmentTree.resize(4*n);
        buildsegmentTree(0,0,n-1,baskets);
        int unplaced=0;
        for(int &fruit: fruits){
            if(!searchquery(fruit,0,0,n-1)) unplaced++;
        }
        return unplaced;
    }
};