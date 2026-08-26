class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int oneCount = 0;

        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '1') {
                oneCount++;
            }

            while (oneCount > k) {
                if (s[left] == '1') {
                    oneCount--;
                }
                left++;
            }

            if (oneCount == k) {

                while (s[left] == '0') {
                    left++;
                }

                string current = s.substr(left, right - left + 1);

                if (ans == "" ||
                    current.size() < ans.size() ||
                    (current.size() == ans.size() && current < ans)) {
                    ans = current;
                }
            }
        }

        return ans;
    }
};