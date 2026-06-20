class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());

        for(int i=0;i<=nums.size();i++){
            if(!mp.count(i)){
                return i;
            }
            mp.insert(i);
        }
        return {};
    }
};