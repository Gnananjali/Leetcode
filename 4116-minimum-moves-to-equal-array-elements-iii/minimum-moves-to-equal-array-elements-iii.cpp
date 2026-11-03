class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < maxNum){
                count += maxNum - nums[i];
            }
        }
        return count;
    }
};