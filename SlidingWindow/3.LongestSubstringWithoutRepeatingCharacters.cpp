class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int l = 0;
        int ans = 0;
        int n = s.size();
        unordered_set<char> charSet;

        for (int r=0;r<n;r++){
            // If current character is already in the window
            while (charSet.find(s[r]) != charSet.end()) {
                // Remove characters from left until no duplicate
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);

            // Update maximum length
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};