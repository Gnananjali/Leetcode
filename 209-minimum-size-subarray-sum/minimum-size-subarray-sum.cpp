class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int sum=0;
        int minLen = INT_MAX;
        for(int right=0;right<nums.size();right++){
            sum += nums[right];
            while(sum >= target){
                minLen = min(right-left+1, minLen);
                sum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX?0:minLen;
    }
};