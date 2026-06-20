class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxVal = 0, res=0;
        for(int num : nums){
            mp[num]++;
        }
        for(auto& it:mp){
            if(it.second > maxVal){
                maxVal = it.second;
                res = it.first;
            }
        }
        return res;
    }
};