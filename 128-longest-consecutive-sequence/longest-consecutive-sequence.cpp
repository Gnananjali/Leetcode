class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> map(nums.begin(), nums.end());
        int longest = 0;
        for(int num:map){
            if(!map.count(num-1)){
                int curr = num;
                int count = 1;
                while(map.count(curr+1)){
                    curr++;
                    count++;
                }
                    longest = max(longest, count);
                
            }
        }
        return longest;
         }
};