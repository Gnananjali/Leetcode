class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> res(n);
        res[0] = cost[0];
        res[1] = cost[1];

        for(int i=2;i<n;i++){
            res[i] = min(res[i-1], res[i-2]) + cost[i];
        }
        return min(res[n-1], res[n-2]);
    }
};