class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> patternToWord;  // pattern → word
        unordered_map<string, char> wordToPattern;  // word → pattern

        // istringstream extract values in the string and change into different type
        istringstream iss(s);
        string word;
        vector<string> words;

        while (iss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) return false;
        
        for (int i = 0; i < pattern.size(); i++) {
            char c1 = pattern[i];
            string s2 = words[i];
            
            // Check if mapping exists and is consistent
            if (patternToWord.count(c1)) {
                if (patternToWord[c1] != s2) return false;
            } else {
                patternToWord[c1] = s2;
            }
            
            // Check reverse mapping to ensure one-to-one
            if (wordToPattern.count(s2)) {
                if (wordToPattern[s2] != c1) return false;
            } else {
                wordToPattern[s2] = c1;
            }
        }
        return true;
    }
};