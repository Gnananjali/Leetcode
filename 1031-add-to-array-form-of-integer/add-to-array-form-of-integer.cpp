class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        vector<int> res;
        int n=num.size();
        
        for(int i=n-1;i>=0;i--){
             
            
            int sum = num[i] + (k%10) + carry;
            int resultdigit = sum%10;
            carry = sum/10;
            k /= 10;
            res.push_back(resultdigit);
        
        }
    while(k>0 || carry>0){
        int sum = k%10 + carry;
        int resultdigit = sum%10;
        carry = sum/10;
        k/=10;
        res.push_back(resultdigit);
    }
        reverse(res.begin(), res.end());
        return res;
    }
};