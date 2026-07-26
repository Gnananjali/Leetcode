class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int left=n-1;left>=0;left--){
            dp[left][left] = 1;
            for(int right = left+1;right<n;right++){
                if(s[left] == s[right]){
                    dp[left][right] = 2+dp[left+1][right-1];
                }else{
                    dp[left][right] = max(dp[left+1][right], dp[left][right-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};