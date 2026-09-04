class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = nums[0];
        vector<int> ans;
        for(int i=0;i<n;i++){
            int minVal = INT_MAX;
            if(nums[i]>maxVal){
                maxVal = nums[i];
            }
            for(int j=i;j<n;j++){
                minVal = min(minVal, nums[j]);
            }
            ans.push_back(maxVal - minVal);
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i] <= k){
                return i;
            }
        }
        return -1;
    }
};