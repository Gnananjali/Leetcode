class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> map;
        int left = 0, maxLen = 0;

        for(int right = 0; right < s.size();right++){
            while(map.count(s[right])){
                map.erase(s[left]);
                left++;
            }
            map.insert(s[right]);
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};