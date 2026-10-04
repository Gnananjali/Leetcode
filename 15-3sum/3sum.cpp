class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int k=0;k<nums.size()-2;k++){
            int left =k+1, right=nums.size()-1;

            if(k>0 && nums[k]==nums[k-1]) continue;
            while(left<right){
            int sum = nums[left]+nums[right]+nums[k];
            if(sum < 0){
                left++;
            }else if(sum > 0){
                right--;
            }else if(sum == 0){
                ans.push_back({nums[left], nums[right], nums[k]});
                left++;
                right--;

                while(left<right && nums[left] == nums[left-1]) left++;
                while(left<right && nums[right] == nums[right+1]) right--;
            }
            }

        }
        return ans;
    }
};