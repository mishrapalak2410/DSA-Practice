class Solution {
public:

    bool check(vector<int>&window,vector<int>&need){
            for(int i=0;i<256;i++){
                if(window[i]<need[i])
                        return false;
            }
            return true;
        }


    string minWindow(string s, string t) {
        vector<int> need(256,0);
        vector<int> window(256,0);
        
        for (int i=0;i<t.size();i++){
             need[t[i]]++;
        }    
        
        int low=0;
        int minlen=INT_MAX;
        int start=0;

        for(int high=0;high<s.size();high++){
            window[s[high]]++;
            while(check(window,need)){
                int currentlen=high-low+1;
                if(minlen>currentlen){
                    minlen=currentlen;
                    start=low;
                }
                window[s[low]]--;
                low++;
            }
        }
        return  minlen==INT_MAX? "":s.substr(start,minlen);
    }
};