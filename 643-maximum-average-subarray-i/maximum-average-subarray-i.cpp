class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int maxVal = INT_MIN;
        int left=0;
        for(int right=0;right<nums.size();right++){
            sum += nums[right];

            if(right-left+1 >= k){
                maxVal = max(maxVal, sum);
                sum -= nums[left];
                left++;
            }
        }
        return (double)maxVal/k;
    }
};