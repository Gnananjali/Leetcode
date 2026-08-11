class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int area = 0;
        
        for(int i=0;i<=n;i++){
            int curr = (i==n?0:heights[i]);
            while(!st.empty() && heights[st.top()] > curr){
                int idx = st.top();
                st.pop();
                int height = heights[idx];
                
                int width = 0;

                if(st.empty()) { 
                width=i;
                }
                else {

                 width = i-st.top()-1;
                }
                

                area = max(height*width, area);
            }
            if(i<n)
                st.push(i);
            
        }
        return area;
    }
};