class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxVal = 0;
        for(int i=0;i<nums.size();i++){
            if(i>maxVal){
                return false;
            }

            maxVal = max(maxVal, i+nums[i]);
            if(maxVal >= nums.size()-1) return true;
            
        }
        return true;
    }
};