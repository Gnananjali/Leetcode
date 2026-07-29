class Solution {
public:
    void solve(int index, vector<int>& candidates, int target, vector<int>& subset, vector<vector<int>>& ans){
        if(target == 0) {
            ans.push_back(subset);
            return;
        }
        if(target < 0 || index == candidates.size()) return;

        subset.push_back(candidates[index]);
        solve(index, candidates, target-candidates[index], subset, ans);
        subset.pop_back();
        solve(index+1, candidates, target, subset, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> ans;
        solve(0, candidates, target, subset, ans);
        return ans;
    }
};