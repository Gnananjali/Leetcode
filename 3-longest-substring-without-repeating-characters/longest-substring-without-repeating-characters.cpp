class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> map;
        int maxVal = 0;
        int left = 0;
        
        for(int right=0;right<s.size();right++){
            while(map.count(s[right])){
                map.erase(s[left]);
                left++;
            }
            map.insert(s[right]);
            maxVal = max(maxVal, right-left+1);
            
        }
        return maxVal;
    }
};