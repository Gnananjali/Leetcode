class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left=0;
        long long sum=0;
        long long maxVal = 0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            mp[nums[right]]++;
            while(mp[nums[right]]>1 || right-left+1>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0)
                mp.erase(nums[left]);

                sum-=nums[left];
                left++;
            }
            if(right-left+1 == k){
                maxVal = max(maxVal, sum);
            }
        }
        return maxVal;
    }
};