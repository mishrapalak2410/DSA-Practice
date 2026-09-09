class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       
        vector <int> ans;
        if(p.size()>s.size())
             return ans;


        vector <int> need(26,0);
        vector <int> window(26,0);

        for(char ch : p){
            need[ch-'a']++;
        }

        int low=0;
        int k=p.size();
        for(int high=0;high<s.size();high++){
            window[s[high]-'a']++;
            int len=high-low+1;
            while(len>k){
                window[s[low]-'a']--;
                low++;
                len=high-low+1;
            }
            if (len==k){
                if(window==need)
                    ans.push_back(high-k+1);
            }
        }
        return ans;

        
    }
};