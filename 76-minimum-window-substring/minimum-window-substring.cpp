class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;

        for(char c : t){
            need[c]++;
        }

        int left = 0, count = t.size(), minLen = INT_MAX, start = 0;
        for(int right = 0; right < s.size();right++){
            if(need[s[right]]>0)
                count--;
            
                need[s[right]]--;
            
            while(count==0){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    start = left;
                }
                    need[s[left]]++;
                
                if(need[s[left]]>0)
                    count++;
                
                    left++;
                
            }

        }
        return minLen == INT_MAX?"":s.substr(start, minLen);
    }
};



Algorithm:
• Create a map need to store frequency of characters in string t

• Count how many total characters are needed → count = size of t

• Initialize:
  left = 0 (start of window)
  minLen = infinity
  start = 0 (starting index of best window)

• Loop with right from 0 to end of string s

  • If current character is needed (need[s[right]] > 0)
    → Decrease count

  • Decrease frequency in map → need[s[right]]--

• When count == 0 (valid window found):

  • Check if current window size is smaller than minLen
    → Update minLen and start

  • Try to shrink window from left:
    → Increase need[s[left]]++
    → If this character becomes required again (need[s[left]] > 0)
      • Increase count

  • Move left++

• After loop ends:
  • If no window found → return empty string
  • Else return substring starting at start of length minLen
