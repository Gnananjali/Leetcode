class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_set<int> map;
        for(int i:bulbs){
            if(map.count(i)){
                map.erase(i);
            }else{
            map.insert(i);
            }
            
        }
        vector<int> res(map.begin(),map.end());

       sort(res.begin(),res.end());
       return res;
    }
};