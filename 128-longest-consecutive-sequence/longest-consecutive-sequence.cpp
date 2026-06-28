class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(int num:nums){
            if(mp.count(num)) continue;
            mp.insert(num);
        }
        int longest = 0;
        for(int num:mp){
            
            if(!mp.count(num-1)){
                int current = num;
                int length = 1;
                while(mp.count(current+1)){
                    current++, length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};