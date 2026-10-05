class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() -1;
        int maxArea = 0;
        int area = 0;
        while(left<right){
            area = abs(right-left)*min(height[left], height[right]);
            maxArea = max(maxArea, area);

            if(height[left]<height[right]) left++;
            else right--;

        }
        return maxArea;
    }
};