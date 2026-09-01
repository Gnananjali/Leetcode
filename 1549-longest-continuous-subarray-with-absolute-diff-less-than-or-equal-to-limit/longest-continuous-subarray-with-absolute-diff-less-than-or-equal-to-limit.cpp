class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;
        int left=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){
            window.insert(nums[right]);
            while(abs(*window.begin() - *window.rbegin()) > limit){
                window.erase(window.find(nums[left]));
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};