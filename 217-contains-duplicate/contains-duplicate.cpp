class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> map;

        for(int num:nums){
            if(map.find(num) != map.end()){
                return true;
            }
            map.insert(num);
        }
        return false;
    }
};