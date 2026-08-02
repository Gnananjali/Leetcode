class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& piles, int left, int right){
        if(left==right){
            return piles[left];
        }
        if(dp[left][right] != INT_MIN) return dp[left][right];
        int leftChoice = solve(piles, left+1, right);
        int rightChoice = solve(piles, left, right-1);

        dp[left][right] = max(leftChoice, rightChoice);
        return dp[left][right];
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp = vector<vector<int>> (n, vector<int>(n, INT_MIN));
        return solve(piles, 0, n-1)>0;
    }
};