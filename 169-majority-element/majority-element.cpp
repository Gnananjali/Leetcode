class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxVal = 0, res = 0;
        for(int num : nums){
            map[num]++;
        }
        for(auto it:map){
            if(it.second > maxVal){
                maxVal = it.second;
                res = it.first;
            }
        }
        return res;
    }
};