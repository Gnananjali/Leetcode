class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> set;
        long long maxSum = 0, currSum = 0;
        int n = nums.size();
        int left = 0;

        for(int right = 0; right < n;right++){
            while(set.count(nums[right])){
                set.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }
            set.insert(nums[right]);
            currSum += nums[right];

            if(right - left + 1 == k){
                maxSum = max(maxSum, currSum);
            
            set.erase(nums[left]);
            currSum -= nums[left];
            left++;
            }
        }
        return maxSum;
    }
};