class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> map;
        map[0]=1;

        int sum = 0,count = 0;
        for(int num : nums){
            sum += num;

            if(map.count(sum-goal)){
                count += map[sum-goal];
            }
            map[sum]++;
        }
        return count;
    }
};