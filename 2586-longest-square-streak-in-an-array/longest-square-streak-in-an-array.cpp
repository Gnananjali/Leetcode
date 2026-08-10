class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> mp(nums.begin(), nums.end());
        int ans = -1;
        
        for(long long num : nums){
            int count=1;
            while(mp.count(num*num)){
            num = num*num;
            count++;
            }
        
        if(count >= 2){
            ans = max(ans, count);
        }
        }
        return ans;
    }
};