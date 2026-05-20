class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxVal = 0, res = 0;
        while(left<right){
            res = (right - left)*min(height[left], height[right]);
            maxVal = max(maxVal, res);

            if(height[left]>height[right]){
                right--;
            }else{
                left++;
            }
        }
        return maxVal;
    }
};