class Solution {
    static void resize(ArrayList<Integer> list, int n, int value) {
    while (list.size() < n) list.add(value);
    while (list.size() > n) list.remove(list.size() - 1);
}
    ArrayList<Integer> maxsegTree= new ArrayList<>();
    ArrayList<Integer> minsegTree= new ArrayList<>();
    ArrayList<Integer> lazy= new ArrayList<>();

   public void propagate(int i, int low, int high){
        int val= lazy.get(i);
        if(val!=0){
            maxsegTree.set(i,maxsegTree.get(i)+val);
            minsegTree.set(i,minsegTree.get(i)+val);
            if(low!=high){
                lazy.set(2*i+1,lazy.get(2*i+1)+val);
                lazy.set(2*i+2,lazy.get(2*i+2)+val);
            }
            lazy.set(i,0);
        }
   }
    public void update(int i, int low, int high, int left, int right,int value){
            propagate(i,low,high);

        if(right < low || left> high){ // completly outside 
            return;
        }
        if(low >= left && high <= right){  // completly inside 
            lazy.set(i,lazy.get(i)+value);
           propagate(i,low,high);
            return;
        }

        int mid = low +(high-low)/2;
        update(2*i+1,low,mid,left,right,value);
        update(2*i+2,mid+1,high,left,right, value);
        minsegTree.set(i,Math.min(minsegTree.get(2*i+1),minsegTree.get(2*i+2)));
        maxsegTree.set(i,Math.max(maxsegTree.get(2*i+1),maxsegTree.get(2*i+2)));
    }
    public int findleftmostzero(int i, int low,int high, int left,int right){

        propagate(i,low,high);
        if (high < left || low > right)
        return -1;

        if(minsegTree.get(i)>0 || maxsegTree.get(i) <0) return -1;
        if(low == high ) return low;
        int mid = low +(high-low)/2;
        int leftresult= findleftmostzero(2*i+1,low,mid,left,right);
        if(leftresult!=-1) return leftresult;   
        return findleftmostzero(2*i+2,mid+1,high,left,right);
    }
    public int longestBalanced(int[] nums) {
        int n= nums.length;
        resize(maxsegTree,4*n,0);
        resize(minsegTree,4*n,0);
        resize(lazy,4*n,0);

        int maxlen=0;
        int cumm[]= new int[n];
        HashMap<Integer,Integer> mp= new HashMap<>();
        for(int r=0;r<n;r++){
            int val=(nums[r]%2==0)? 1: -1;
            int prev=-1;
            if(mp.containsKey(nums[r])){
                prev=mp.get(nums[r]);
            }

            if(prev!=-1){ // we have seen this element in past 
                // for(int l=0;l<=prev;l++){ // range update from(0...prev)
                //     cumm[l] -= val;
                // }

                update(0,0,n-1,0,prev,-val);
            }
            // for(int l=r;l>=0;l--){  // range update from (0...r)
            //     cumm[l]+=val;
            // }

            update(0,0,n-1,0,r,val);

            // for(int l=0;l<=r;l++){  // finding leftmost 0 in segtree
            //     if(cumm[l]==0){
            //         maxlen= Math.max(maxlen,r-l+1);
            //         break;
            //     }
            // }

            int l= findleftmostzero(0,0,n-1,0,r);
            if(l!=-1) maxlen= Math.max(maxlen,r-l+1);
            mp.put(nums[r],r);
        }

       return maxlen;
    }
}