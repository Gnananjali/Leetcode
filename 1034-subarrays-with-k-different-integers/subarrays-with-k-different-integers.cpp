class Solution {
public:
     int atMostK(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int ans=0;
        int left=0;
        int distinct = 0;
        for(int right=0;right<nums.size();right++){
            mp[nums[right]]++;
            if(mp[nums[right]] == 1) distinct++;
            while(distinct > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    distinct--;
                    
                }
                left++;
            }
            ans += right-left+1;
        }
        return ans;
    }


int subarraysWithKDistinct(vector<int>& nums, int k){
    return atMostK(nums, k) - atMostK(nums, k-1);
}
};