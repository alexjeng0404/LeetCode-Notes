// ref:https://medium.com/leetcode-%E6%BC%94%E7%AE%97%E6%B3%95%E6%95%99%E5%AD%B8/035-leetcode-76%E6%BC%94%E7%AE%97%E6%B3%95-minimum-window-substring-%E6%9C%80%E5%B0%8F%E7%AA%97%E5%8F%A3%E5%AD%90%E5%AD%97%E4%B8%B2-6513c9ef03f4
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
                // get j position
                char currentChar = s[j];
                j += 1;

                // add 1 to currentChar
                cnt[currentChar] = cnt[currentChar] + 1;
                int newCount = cnt[currentChar];
                if (newCount > 0) {
                    total = total + 1;
                }
            }
        }
        
        return (min_len == INT_MAX) ? "" : s.substr(from, min_len);
    }
};