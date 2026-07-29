class Solution {
public:
    void solve(vector<int>& nums, vector<int>& visited, vector<int>& subset, vector<vector<int>>& ans){
        if(subset.size() == nums.size()){
            ans.push_back(subset);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]){
                continue;
            }

            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]){
                continue;
            }
            visited[i] = true;
            subset.push_back(nums[i]);
            solve(nums, visited, subset, ans);

            
            visited[i] = false;
            subset.pop_back();
            
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> visited(n, false);
        vector<int> subset;
        vector<vector<int>> ans;
        solve(nums, visited, subset, ans);
        return ans;
    }
};