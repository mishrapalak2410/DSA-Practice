class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int ns1=s1.size();
        int ns2=s2.size();
        if(ns1>ns2)
             return false;
        
        vector<int> need(26,0);
        vector <int> window(26,0);

        for(char ch : s1){
            need[ch-'a']++;
        }

        int low=0;
    
        for(int high=0;high<ns2;high++){
            window[s2[high]-'a']++;
            int len=high-low+1;
            while(len>ns1){
                window[s2[low]-'a']--;
                low++;
                len=high-low+1;
            }
            if (window==need)
                   return true;

        }
        return false;

        
    }
};