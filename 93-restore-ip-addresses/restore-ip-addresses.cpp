class Solution {
public:
    bool isValid(string part){
        if(part.size() > 1 && part[0]=='0') return false;
        if (stoi(part) > 255) return false;
        else return true;
    }
    void solve(int index, string& s, vector<string>& subset, vector<string>& ans){
        if(index == s.size() && subset.size()==4){
            string ip = "";
            for(int i=0;i<4;i++){
                ip+=subset[i];

                if(i != 3)
                ip += ".";
            }
            ans.push_back(ip);
            return;
        }
        if(index == s.size() || subset.size() == 4) return;
        for(int end = index; end<min(index+3,(int)s.size());end++){
            string part = s.substr(index, end-index+1);
            if(isValid(part)){
                subset.push_back(part);
                solve(end+1, s, subset, ans);
                subset.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> subset;
        vector<string> ans;
        solve(0, s, subset, ans);
        return ans;
    }
};