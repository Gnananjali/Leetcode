class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> map;
        int left=0;
        long long currSum = 0;
        long long maxVal = 0;
        for(int right=0;right<nums.size();right++){
            while(map.count(nums[right])){
                
                map.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }
            map.insert(nums[right]);
            currSum += nums[right];

            while(right-left+1 > k){
                map.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }

            if(right-left+1 == k){
                maxVal = max(maxVal, currSum);
            }
        }
        return maxVal;
    }
};