class Solution {
public:
    int addDigits(int num) {
       if(num == 0) return 0;
       return 1 + (abs(num)-1) % 9; 

    }
};