class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                return true;
            }
            mp.insert(nums[i]);
        }
        return false;
    }
};