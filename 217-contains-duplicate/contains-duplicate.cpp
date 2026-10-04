class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mp;
        for(int i:nums){
            if(mp.count(i)){
                return true;
            }
            mp.insert(i);
        }
        return false;
    }
};