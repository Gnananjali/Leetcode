class Solution {
public:
    unordered_map<int, bool> dp;
    int maxNum;
    bool dfs(int mask, int remaining){
        if(remaining <= 0) return false;
        if(dp.count(mask)) return dp[mask];
        for(int i=1;i<=maxNum;i++){
            if(mask & (1 << (i-1))){

             continue;
            }
            int newMask = mask | (1 << (i-1));
            if(!dfs(newMask, remaining - i)){
                dp[mask] = true;
                return true;
            }

        }


        dp[mask] = false;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxNum = maxChoosableInteger;
        if(desiredTotal <= 0) return true;

        int total = maxNum * (maxNum+1)/2;
        if(total < desiredTotal) return false;

        return dfs(0, desiredTotal);
    }
};