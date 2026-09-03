class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int high=0;
        int low=0;
        unordered_map<int,int>freq;
        int res=INT_MIN;
        for(;high<fruits.size();high++){
            freq[fruits[high]]++;
            while (freq.size()>2){
                freq[fruits[low]]--;
                if (freq[fruits[low]]==0)
                       freq.erase(fruits[low]);
                low++;
            }
            int len=high-low+1;
            res=max(len,res);
        }
        return res;

    }
};