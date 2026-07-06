class Solution {
public:
    int greatestD(int n){
        // for(int i=n/2;i>=1;i--){
        //     if(n%i==0) return i;
        // }
        // return 1;

        // Divisor always comes in pair 
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return (n/i);
            }
        }
        return 1;
    }
    int minSteps(int n) {
        // using iterative solution 
        // int count=0;
        // while(n>1){
        //     int hf= greatestD(n);
        //     count+=(n/hf);
        //     n=hf;
        // }
        // return count;

        // using lon(n) average time complexity 

        int count=0;
        if(n==1) return 0;
        for(int i=2;i*i<=n;i++){
                while(n%i==0){
                    count+=i;
                    n/=i;
            }
        }
       if(n>1) count+=n;
        return count;
    }
};