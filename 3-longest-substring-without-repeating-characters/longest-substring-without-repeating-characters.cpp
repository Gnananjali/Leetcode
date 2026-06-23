class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;
        int left=0;
        int maxLen = 0;
        for(int right=0;right<s.size();right++){
            while(mp.count(s[right])){
                mp.erase(s[left]);
                left++;
            }
            mp.insert(s[right]);
            maxLen = max(maxLen, right-left+1);
            }
                
        
        return maxLen;
    }
};