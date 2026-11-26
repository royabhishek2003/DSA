class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        n-=10;
        int shoulddecrease=9;
        string turn= "bob";
        while(n >= shoulddecrease){
            n-=shoulddecrease;
            if(turn=="bob") turn="alice";
            else turn="bob";
            shoulddecrease-=1;
        }
        if(turn=="bob"){
            return true;
        }
        return false;
    }
};