class Solution {
public:
    void backtrack(int index, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result){
        
        if(target==0){
            result.push_back(current);
            return;
        }
        if(target<0) return;
        for(int i=index;i<candidates.size();i++){
            current.push_back(candidates[i]);
            backtrack(i, candidates, target-candidates[i], current, result);
            current.pop_back();
        }


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;

        backtrack(0, candidates, target, current, result);
        return result;
    }
};