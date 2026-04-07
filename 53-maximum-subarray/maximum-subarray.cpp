class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxVal = INT_MIN;
        for(int num:nums){
            currSum += num;
            maxVal = max(maxVal, currSum);

            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxVal;

    }
};