class Solution {
public:
    string s;
    int pos;

    set<string> parseExpression() {
        set<string> result;

        while (pos < s.size() && s[pos] != '}') {
            set<string> cur = parseTerm();

            result.insert(cur.begin(), cur.end());

            if (pos < s.size() && s[pos] == ',')
                pos++;
        }

        return result;
    }

    set<string> parseTerm() {
        set<string> result = {""};

        while (pos < s.size() &&
               s[pos] != '}' &&
               s[pos] != ',') {

            set<string> cur;

            if (s[pos] == '{') {
                pos++;
                cur = parseExpression();
                pos++;
            } else {
                cur.insert(string(1, s[pos]));
                pos++;
            }

            set<string> next;

            for (string a : result) {
                for (string b : cur) {
                    next.insert(a + b);
                }
            }

            result = next;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};