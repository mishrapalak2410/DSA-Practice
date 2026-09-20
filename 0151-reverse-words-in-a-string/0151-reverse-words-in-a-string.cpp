class Solution {
public:
    string reverseWords(string s) {
        
        // Remove extra spaces
        int i = 0;
        int j = 0;

        while (i < s.size()) {
            while (i < s.size() && s[i] == ' ') {
                i++;
            }

            while (i < s.size() && s[i] != ' ') {
                s[j++] = s[i++];
            }

            while (i < s.size() && s[i] == ' ') {
                i++;
            }

            if (i < s.size()) {
                s[j++] = ' ';
            }
        }

        s.resize(j);

        // Reverse entire string
        reverse(s.begin(), s.end());

        // Reverse every individual word
        int start = 0;

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
        
    }
};