class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(128, 0);
        
        // Count characters in t
        for (char c : t) {
            cnt[c]++;
        }
        
        int from = 0; // start index of minimum window
        int total = t.length(); // number of characters needed to match
        int min_len = INT_MAX; // minimum window length
        
        // Sliding window
        for (int i = 0, j = 0; i < s.length(); i++) {
            // If current character is in t, decrement total
            if (cnt[s[i]]-- > 0) {
                total--;
            }
            
            // When we have all characters from t in current window
            while (total == 0) {
                // Update minimum window
                if (i - j + 1 < min_len) {
                    min_len = i - j + 1;
                    from = j;
                }
                
                // Move left pointer and adjust counts
                if (++cnt[s[j++]] > 0) {
                    total++;
                }
            }
        }
        
        return (min_len == INT_MAX) ? "" : s.substr(from, min_len);
    }
};