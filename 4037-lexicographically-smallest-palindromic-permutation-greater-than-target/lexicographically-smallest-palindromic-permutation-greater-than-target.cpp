class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int halfLen = n / 2;

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Check if s can form a palindrome
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        // Characters available for the first half
        vector<int> halfFreq(26);

        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        string answer = "";

        // Try every position as the FIRST position
        // where our first half becomes greater than target.
        for (int pos = halfLen - 1; pos >= 0; pos--) {

            vector<int> remaining = halfFreq;
            string half = "";
            bool possible = true;

            // Make positions [0 ... pos-1] equal to target
            for (int i = 0; i < pos; i++) {
                int x = target[i] - 'a';

                if (remaining[x] == 0) {
                    possible = false;
                    break;
                }

                remaining[x]--;
                half += target[i];
            }

            if (!possible)
                continue;

            // At pos, choose the smallest character
            // strictly greater than target[pos].
            int x = target[pos] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (remaining[c] == 0)
                    continue;

                string newHalf = half;
                newHalf += char('a' + c);

                remaining[c]--;

                // Fill remaining half with smallest characters
                for (int j = 0; j < 26; j++) {
                    while (remaining[j] > 0) {
                        newHalf += char('a' + j);
                        remaining[j]--;
                    }
                }

                // Build palindrome
                string candidate = newHalf;

                if (n % 2 == 1) {
                    candidate += middle;
                }

                string rev = newHalf;
                reverse(rev.begin(), rev.end());

                candidate += rev;

                if (candidate > target &&
                    (answer.empty() || candidate < answer)) {
                    answer = candidate;
                }

                // Restore for next c
                remaining = halfFreq;

                for (int i = 0; i < pos; i++) {
                    remaining[target[i] - 'a']--;
                }
            }
        }

        // Also check the palindrome whose first half
        // is exactly equal to target's first half.
        vector<int> remaining = halfFreq;
        string half = "";
        bool possible = true;

        for (int i = 0; i < halfLen; i++) {
            int x = target[i] - 'a';

            if (remaining[x] == 0) {
                possible = false;
                break;
            }

            remaining[x]--;
            half += target[i];
        }

        if (possible) {
            string candidate = half;

            if (n % 2 == 1) {
                candidate += middle;
            }

            string rev = half;
            reverse(rev.begin(), rev.end());

            candidate += rev;

            if (candidate > target &&
                (answer.empty() || candidate < answer)) {
                answer = candidate;
            }
        }

        return answer;
    }
};