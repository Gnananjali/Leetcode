class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> fruit;
        int left=0;
        int count=0;
        for(int right=0;right<fruits.size();right++){
            fruit[fruits[right]]++;

            while(fruit.size() >2){
                
                fruit[fruits[left]]--;
                if(fruit[fruits[left]] == 0){
                    fruit.erase(fruits[left]);
                }
                left++;
            }
            count = max(count, right-left+1);
        }
        return count;
    }
};