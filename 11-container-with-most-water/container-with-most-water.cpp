class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right = height.size()-1;
        int maxVal=0,res=0;
        while(left < right){
        
            res = (right-left)*min(height[left], height[right]);
            maxVal = max(res, maxVal);
            
            if(height[left] > height[right]){
                right--;
            }else{
            left++;
        }
        }
        
        return maxVal;
    }
};