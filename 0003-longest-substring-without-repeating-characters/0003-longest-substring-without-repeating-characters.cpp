class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int high=0;
        int low=0;
        unordered_map<char,int>freq;
        int res=INT_MIN;
        for(;high<s.size();high++){
            freq[s[high]]++;
             int k=high-low+1;
            while(freq.size()<k){
                freq[s[low]]--;
                if (freq[s[low]]==0)
                      freq.erase(s[low]);
                low++;
                k=high-low+1;
            }
            res=max(res,high-low+1);
        } 
        return res==INT_MIN? 0:res;  
    }
};