class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int maxSum=INT_MIN;
        int sum=0;
        for(int right=0;right<nums.size();right++){
            sum += nums[right];


            if(right-left+1 == k){
                maxSum = max(maxSum, sum);
                sum -= nums[left];
                left++;
            }
        }
        return (double)maxSum/k;
    }
};