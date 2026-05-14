class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0] = 1;
        int currSum = 0, result = 0;
        for(int num:nums){
            currSum += (num % 2);

            if(map.count(currSum-k)){
                result += map[currSum-k];
            }
            map[currSum]++;
        }
        return result;
    }
};