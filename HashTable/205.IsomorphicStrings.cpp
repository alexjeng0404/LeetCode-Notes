class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, char> mapST;  // s to t mapping
        unordered_map<char, char> mapTS;  // t to s mapping
        
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            
            // Check if mapping exists and is consistent
            if (mapST.count(c1)) {
                if (mapST[c1] != c2) return false;
            } else {
                mapST[c1] = c2;
            }
            
            // Check reverse mapping to ensure one-to-one
            if (mapTS.count(c2)) {
                if (mapTS[c2] != c1) return false;
            } else {
                mapTS[c2] = c1;
            }
        }
        
        return true;
    }
};