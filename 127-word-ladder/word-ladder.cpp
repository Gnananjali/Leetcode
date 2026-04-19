class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> map(wordList.begin(), wordList.end());
        if(map.find(endWord) == map.end()) return 0;

        queue<string> q;
        q.push(beginWord);

        int steps = 1;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                string word = q.front();
                q.pop();

                if(word == endWord) return steps;

                for(int j=0;j<word.size();j++){
                    char original = word[j];

                    for(char c='a';c<='z';c++){
                        word[j] = c;

                        if(map.find(word) != map.end()){
                            q.push(word);
                            map.erase(word);
                        }
                    }
                    word[j] = original;
                }
            }
            steps++;
        }
        return 0;
    }
};