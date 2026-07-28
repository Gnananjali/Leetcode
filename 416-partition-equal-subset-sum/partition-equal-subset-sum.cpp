class Solution {
public:
    vector<vector<int>> dp;
    bool canMakeTarget(vector<int>& nums, int index, int target){
        if(target == 0) return true;
        if(index == nums.size()) return false;

        

        if(dp[index][target] != -1)
            return dp[index][target];

        bool skip = canMakeTarget(nums, index+1, target);
        bool take = false;


        if(nums[index] <= target){
            take = canMakeTarget(nums, index+1, target-nums[index]);
        }
        dp[index][target] = take||skip;
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%2!=0) return false;
        int target = sum/2;

        dp.assign(nums.size() + 1, vector<int>(target+1, -1));

        return canMakeTarget(nums, 0, target);
    }
};