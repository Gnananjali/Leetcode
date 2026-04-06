class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> map(nums.begin(), nums.end());

        int i=1;
        while(true){
            if(!map.count(i)){
                return i;
            }
            i++;
        }
    }
};