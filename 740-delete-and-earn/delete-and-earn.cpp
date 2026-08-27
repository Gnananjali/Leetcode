class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1);
        for(auto &it:mp){
            int x = it.first;
            int freq = it.second;

            points[x] = x*freq;
        }
        vector<int> dp(maxVal+1);
        dp[0] = points[0];
        dp[1] = max(points[0], points[1]);

        for(int i=2;i<=maxVal;i++){
            dp[i] = max(dp[i-1], points[i]+dp[i-2]);
        }
        return dp[maxVal];
    }
};