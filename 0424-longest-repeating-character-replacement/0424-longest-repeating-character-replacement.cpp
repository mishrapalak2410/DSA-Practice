class Solution {
public:
    int characterReplacement(string s, int k) {
        int low=0;
        int maxfreq=0;
        int ans=0;
        vector<int> freq(26,0);
        for(int high=0;high<s.size();high++){
            freq[s[high]-'A']++;
            maxfreq=max(maxfreq,freq[s[high]-'A']);
            int changes=(high-low+1)-maxfreq;
            if(changes>k){
                freq[s[low]-'A']--;
                low++;
            }
            ans=max(ans,high-low+1);

        }
        return ans;
        
    }
};