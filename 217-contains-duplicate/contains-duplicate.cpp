class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> map;
        for(int i:nums){
            if(map.count(i)){
                return true;
            }else{
                map.insert(i);
            }
        }
        return false;
    }
};