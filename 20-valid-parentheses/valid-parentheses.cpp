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




Algorithm:
Create an empty stack to store opening brackets

• Traverse each character in the string

  • If character is an opening bracket (, {, [
    → Push it into the stack

  • Else (it is a closing bracket):

    • If stack is empty → return false

    • If top of stack does not match the corresponding opening bracket
      → return false

    • Else pop the top element from the stack

• After traversing the string:

  • If stack is empty → return true
  • Else → return false
