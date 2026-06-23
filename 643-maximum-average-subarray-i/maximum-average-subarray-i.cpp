class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0;
        long long maxSum = INT_MIN;
        long long currSum = 0;
        for(int right=0;right<nums.size();right++){
            currSum += nums[right];

            if(right-left+1 == k){
                
                maxSum = max(maxSum, currSum);
                currSum -= nums[left];
                left++;
            }
        }
        return (double)maxSum/k;
    }
};