class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for(int i=0;i<order.size();i++){
            map[order[i]] = i;
        }
        for(int i=0;i<words.size()-1;i++){
            string a = words[i];
            string b = words[i+1];

            bool founddiff = false;

            int len = min(a.size(), b.size());
            for(int j = 0;j<len;j++){
                if(a[j] != b[j]){
                    if(map[a[j]] > map[b[j]]){
                        return false;
                    }
                    founddiff = true;
                    break;
                }
            }
            if(!founddiff && a.size() > b.size()){
                return false;
            }
        }
        return true;
    }
};