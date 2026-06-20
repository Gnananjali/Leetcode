class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        long long sum = 0;
        long long maxVal = INT_MIN;
        //long long avg = 0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            if(right-left+1 == k){
                maxVal = max(maxVal, sum);
                sum -= nums[left];

                //avg = sum/k;
                left++;

            }
           // maxVal = max(maxVal, avg);
        }
        return (double)maxVal/k;
    }
};