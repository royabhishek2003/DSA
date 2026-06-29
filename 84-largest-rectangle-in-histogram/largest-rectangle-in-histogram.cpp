class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // approach -1 just precompute next smallar right and next smaller left for each index using stack and calculate the area for each index and maintain the max area 

        // int n= heights.size();
        // vector<int> right(n);
        // vector<int> left(n);
        // stack<int> st;
        // // finding the next smallar right
        // for(int i=0;i<n;i++){
        //     while(!st.empty() && heights[st.top()] > heights[i]){
        //         right[st.top()]= i;
        //         st.pop();
        //     }
        //     st.push(i);
        // }
        // while(!st.empty()){
        //     right[st.top()]=n;
        //     st.pop();
        // }

        // // finding the next smallar left 
        // for(int i=n-1;i>=0;i--){
        //      while(!st.empty() && heights[st.top()] > heights[i]){
        //         left[st.top()]= i;
        //         st.pop();
        //     }
        //     st.push(i);
        // }
        //  while(!st.empty()){
        //     left[st.top()]=-1;
        //     st.pop();
        // }

        // int area=0;
        // for(int i=0;i<n;i++){
        //     area= max(area, heights[i]*(right[i]-left[i]-1));
        // }
        // return area;

        // approach -2 

        int n= heights.size();
        stack<int> st;
        int maxarea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i] < heights[st.top()]){  // next smallest right -> i 
                    int idx= st.top();
                    st.pop();
                    if(st.empty()){
                        maxarea= max(maxarea, heights[idx]*i);
                    }else{
                        maxarea= max(maxarea, heights[idx]* (i-st.top()-1));
                    }
            }
            st.push(i);
        }
        while(!st.empty()){
            int idx= st.top();
            st.pop();
            if(st.empty()){
                maxarea= max(maxarea, heights[idx]*n);
            }else{
                maxarea= max(maxarea, heights[idx]* (n-st.top()-1));
            }
        }
        return maxarea;

    }
};