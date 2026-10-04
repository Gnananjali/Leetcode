class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;
        
        int left=0;
        
        int maxCount = 0;
        for(int right=0;right<s.size();right++){
            while(mp.count(s[right])){
                mp.erase(s[left]);
                left++;
                
            }
            mp.insert(s[right]);
                maxCount = max(maxCount, right-left+1);
        }
        return maxCount;
    }
};