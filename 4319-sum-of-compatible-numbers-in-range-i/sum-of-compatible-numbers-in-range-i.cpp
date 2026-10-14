class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int i = max(1, n-k);
        vector<int> dp((n+k)+1, 0);
        
        for(int x=i;x<=n+k;x++){
            dp[x] = dp[x-1];
            if(abs(n-x)<=k && (n&x)==0){
                dp[x] += x;
            }
        }
        return dp[n+k];
    }
};