class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());
        
        int currSum = nums[0];
        
        for(int i=1;i<nums.size();i++){
            
            if(nums[i] == nums[i-1]+1){
                currSum+=nums[i];
            }else{
                break;
            }
        }
        while(mp.count(currSum)){
            currSum++;
        }
        
        return currSum;
    }
};