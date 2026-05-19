class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> map;
        for(int num:nums){
            map.insert(num);
        }
        for(int i=1;i<=nums.size()+1;i++){
            if(map.count(i)){
            continue;
            }else{
                return i;
            }
        }
        return 1;
    }
};