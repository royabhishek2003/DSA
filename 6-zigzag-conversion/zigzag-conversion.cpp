class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<vector<char>> temp(numRows);
        int i=0;
        bool reverseorder=false;
        for(char &ch: s){
            temp[i].push_back(ch);
            if(reverseorder==false){
                i++;
                if(i==numRows){
                    i=numRows-2;
                    reverseorder=true;
                }
            }
            else if(reverseorder==true){
                i--;
                if(i<0){
                    i=1;
                    reverseorder=false;
                }
            }
        }

        string result="";
        for(vector<char> &vec: temp){
            for(char &ch: vec) result +=ch;
        }

        return result;
    }
};