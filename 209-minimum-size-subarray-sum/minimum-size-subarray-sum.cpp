class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int currSum = 0, minVal = INT_MAX;
        for(int right = 0;right<nums.size();right++){
            currSum += nums[right];

            while(currSum >= target){
                minVal = min(minVal, right-left+1);
                currSum -= nums[left];
                
                left++;
            }
            
        }
        return minVal == INT_MAX ? 0 : minVal;
    }
};