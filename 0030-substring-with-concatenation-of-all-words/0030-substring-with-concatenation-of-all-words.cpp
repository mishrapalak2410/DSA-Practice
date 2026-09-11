class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int n = words[0].size();
        int total = words.size();

        unordered_map<string, int> need;

        for (string word : words)
            need[word]++;

        for (int start = 0; start < n; start++) {

            int low = start;
            int count = 0;

            unordered_map<string, int> window;

            for (int high = start; high + n <= s.size(); high += n) {

                string word = s.substr(high, n);

                // word is not required
                if (!need.count(word)) {
                    window.clear();
                    count = 0;
                    low = high + n;
                    continue;
                }

                window[word]++;
                count++;

                // Too many same words
                while (window[word] > need[word]) {

                    string left = s.substr(low, n);

                    window[left]--;
                    low += n;
                    count--;
                }

                // All words found
                if (count == total) {
                    ans.push_back(low);

                    string left = s.substr(low, n);
                    window[left]--;
                    low += n;
                    count--;
                }
            }
        }

        return ans;
    }
};
        