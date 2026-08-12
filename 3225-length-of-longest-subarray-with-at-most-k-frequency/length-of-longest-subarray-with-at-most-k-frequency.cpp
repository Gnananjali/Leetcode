class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left=0,right=0;
        int len=0, maxLen = 0;
        for(right=0;right<nums.size();right++){
            mp[nums[right]]++;
            while(mp[nums[right]]>k){
                mp[nums[left]]--;
                left++;
                
            }
            
            len = right-left+1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};