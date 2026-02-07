class Solution {
public:
    bool isValid(string s) {
        std::stack<char> sta;
        for(char ch:s){
            if(ch=='(' || ch=='{' || ch=='['){
                sta.push(ch);
            }else{
                if(sta.empty() || (ch==')' && sta.top()!='(') || (ch=='}' && sta.top()!='{') || (ch==']' && sta.top()!='[')){
                    return false;
                }
                sta.pop();
            }
        }
        return sta.empty();
    }
};