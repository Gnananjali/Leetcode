class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26, 0);
        vector<int> window(26, 0);
        int k = s1.size();
        for(char c:s1){
            need[c - 'a']++;
        }
        for(int i=0;i<s2.size();i++){
            window[s2[i] - 'a']++;

            if(i >= k){
                window[s2[i-k] - 'a']--;
            }
            if(i >= k-1){
                if(need == window)
                return true;
            }
        }
        return false;
    }
};