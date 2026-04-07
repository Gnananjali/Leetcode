class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> map;
        for(int num:nums){
            if(map.count(num)){
                return true;
            }else{
                map.insert(num);
            }
        }
        return false;
    }
};