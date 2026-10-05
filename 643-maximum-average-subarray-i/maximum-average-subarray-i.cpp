class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0;
        long long sum = 0;
        long long maxSum = LLONG_MIN;
        for(int right=0;right<nums.size();right++){
            sum += nums[right];
            while(right-left+1 > k){
                sum -= nums[left];
                left++;
                
            }
            if(right-left+1 == k){
                maxSum = max(maxSum, sum);
            }
        }
        return (double)maxSum/k;

    }
};