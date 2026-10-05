class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26, 0);
        vector<int> window(26, 0);
        int left = 0;
        for(int right=0;right<s1.size();right++){
            need[s1[right] - 'a']++;
        }
        for(int right=0;right<s2.size();right++){
            window[s2[right] - 'a']++;
            while(right-left+1 > s1.size()){
                window[s2[left] - 'a']--;
                left++;
            }
            if(window == need) return true;
        }
        return false;
    }
};