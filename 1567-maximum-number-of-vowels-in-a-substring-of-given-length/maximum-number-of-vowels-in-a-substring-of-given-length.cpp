class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int left=0;
        int maxCount=0, count=0;
        for(int right=0;right<s.size();right++){
            if(isVowel(s[right])) count++;
            if(right-left+1 == k){
                maxCount = max(maxCount, count);
                if(isVowel(s[left])) count--;
                left++;
            }
        }
        return maxCount;
    }
};