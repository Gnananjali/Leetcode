class Solution {
public:
    bool isValid(string s) {
        int balance=0;

        for(char c:s){
            if(c=='(') balance++;
            else if(c==')'){
                balance--;
                if(balance<0) return false;
            }
        }

        return balance==0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> cur;
        cur.insert(s);

        while(true){
            for(string str:cur){
                if(isValid(str))
                    ans.push_back(str);
            }

            if(!ans.empty())
                return ans;

            unordered_set<string> next;

            for(string str:cur){
                for(int i=0;i<str.size();i++){
                    if(str[i]!='(' && str[i]!=')')
                        continue;

                    next.insert(str.substr(0,i)+str.substr(i+1));
                }
            }

            cur=next;
        }
    }
};