class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(int i:nums){
            mp.insert(i);
        }
        
        
        int maxCount = 0;
        for(int i:mp){
            if(mp.count(i - 1)){
                continue;
            }
            int start = i;
            int count = 1;
            
            while(mp.count(start+1)){
            count++;
            start++;
        }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};