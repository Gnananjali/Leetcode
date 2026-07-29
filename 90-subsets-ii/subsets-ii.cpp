class Solution {
public:

    void solve(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        solve(index+1, nums, subset, ans);
        subset.pop_back();
        while(index+1 < nums.size() && nums[index]==nums[index+1]){
            index++;
        }
        solve(index+1, nums, subset, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> ans;

        solve(0, nums, subset, ans);
        return ans;
    }
};