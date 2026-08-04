class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it:mp){
            int freq = it.second;
            char ch = it.first;

            pq.push({freq, ch});
        }
            string ans;
            while(!pq.empty()){
                int freq = pq.top().first;
                char ch = pq.top().second;
                pq.pop();
                while(freq != 0){
                    ans.push_back(ch);
                    freq--;
                }
            }
            return ans;
    }
};