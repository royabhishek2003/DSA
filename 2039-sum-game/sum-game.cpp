class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftKnownSum = 0;
        int rightKnownSum = 0;

        int leftQnMarkCount = 0;
        int rightQnmarkCount = 0;

        for(int i = 0; i < n; i++) {
            if(num[i] == '?') {
                if(i < n/2) {
                    leftQnMarkCount++;
                } else {
                    rightQnmarkCount++;
                }
            } else {
                if(i < n/2) {
                    leftKnownSum += num[i] - '0';
                } else {
                    rightKnownSum += num[i] - '0';
                }
            }
        }

        int totalQnMarks = leftQnMarkCount + rightQnmarkCount;
        if(totalQnMarks % 2 == 1) { //Odd - alice always wins
            return true;
        }
        // mathematical trick bob tries to limit the alice by k means if alice choose x then bob should choose k-x so that the increment is limited to k and if alice choose 9 then bob can only choose 9 cause then only valid value of bob will be there aso k= 9 is the only safe option 
        // leftsum = leftknownsum + 4.5*leftquestionmark(because 2 question mark combines the sum 9 so for each 4.5 is there )
        // similarly rightsum= rightknownsum + 4.5*rightquestionmark

        // and if (left == right) then return false otherwise true 
        int LEFT = 2 * leftKnownSum + 9*leftQnMarkCount;

        int RIGHT = 2 * rightKnownSum + 9*rightQnmarkCount;

        if(LEFT == RIGHT) //Bob wins
            return false;

        return true;
    }
};
