class Solution {
public:
    bool validDigit(int n, int x) {
        string st = to_string(n);
        char num = x + '0';
        for(int i=0;i<st.size();i++){
            if(st[i] == num && st[0]!=num) return true;
        }
        return false;
    }
};