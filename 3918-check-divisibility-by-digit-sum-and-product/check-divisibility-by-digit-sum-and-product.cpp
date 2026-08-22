class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int num=n;
        while(n){
            int rem= n%10;
            n/=10;
            sum+=rem;
            product*=rem;
        }
        if(num%(product + sum) ==0) return true;
        return false;
    }
};