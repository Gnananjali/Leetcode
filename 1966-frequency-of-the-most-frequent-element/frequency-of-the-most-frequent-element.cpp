class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left=0;
        long long sum=0;
        int maxSize=INT_MIN;
        for(int right=0;right<nums.size();right++){
            sum += nums[right];

            long long cost = 1LL * nums[right] * (right - left + 1) - sum;
        
        while(cost > k){
            sum -= nums[left];
            left++;

            cost = 1LL * nums[right] * (right - left + 1) - sum;

        }
        
            maxSize = max(maxSize, right-left+1);
        
        }
        return maxSize;
    }
};