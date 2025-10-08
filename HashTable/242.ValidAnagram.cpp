class Solution {
public:
    /**
     * @brief Checks if string t is an anagram of string s using a Hash Map (Unordered Map).
     * @param s The first string.
     * @param t The second string.
     * @return true if t is an anagram of s, false otherwise.
     */
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()){
            return false;
        }
        
        // Use an unordered_map to store the frequency of characters in string s.
        // Key: character (char), Value: frequency (int).
        unordered_map <char, int> map;
        
        for (char ch : s){
            map[ch] += 1;
        }
        
        for (char ch : t){
            // if t has a word not in s 
			// or t has more same character than s
            if (map.find(ch) == map.end() || map[ch] == 0){
                return false;
            }
            
            map[ch] -= 1;
        }
        
        return true;
    }
};
