class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int left, int right){
        
        if(left==right){
            return nums[left];
        }
        if(dp[left][right] != INT_MIN) return dp[left][right];
        int leftChoice = nums[left] - solve(nums, left+1, right);
        int rightChoice = nums[right] - solve(nums, left, right-1);

        dp[left][right] = max(leftChoice, rightChoice);
        return dp[left][right];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int left=0, right=n-1;
        dp = vector<vector<int>> (n, vector<int>(n, INT_MIN));
        return solve(nums, 0, n-1) >= 0;
    }
};
