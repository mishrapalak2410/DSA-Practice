class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // Frequency of characters required
        for(char ch : t) {
            need[ch]++;
        }

        int low = 0;
        int count = 0;

        int minlen = INT_MAX;
        int start = 0;

        for(int high = 0; high < s.size(); high++) {

            // Add character to window
            window[s[high]]++;

            // Character contributes to required count
            if(need.count(s[high]) &&
               window[s[high]] <= need[s[high]]) {
                count++;
            }

            // Current window is valid
            while(count == t.size()) {

                int currentlen = high - low + 1;

                if(currentlen < minlen) {
                    minlen = currentlen;
                    start = low;
                }

                // Remove left character
                window[s[low]]--;

                if(need.count(s[low]) &&
                   window[s[low]] < need[s[low]]) {
                    count--;
                }

                low++;
            }
        }

        if(minlen == INT_MAX)
            return "";

        return s.substr(start, minlen);
    }
};