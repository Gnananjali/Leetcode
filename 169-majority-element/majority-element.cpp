class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int num:nums){
            map[num]++;
        }
        int maxFreq = 0;
        int result = -1;

        for(auto it :map){
            if(it.second > maxFreq){
                maxFreq = it.second;
                result = it.first;
            }
        }
        return result;
    }
};