class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<int> dp(n+1, 1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>0;j--){
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp;
    }
};