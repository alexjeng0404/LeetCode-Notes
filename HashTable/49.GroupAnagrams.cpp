#include <string>

class Solution {
public:
    /**
     * @brief Groups anagrams together using the sorted string as a unique hash key.
     * @param strs The input list of strings.
     * @return A list of lists, where each inner list contains a group of anagrams.
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // string->string where key is the sorted string and value is unsorted ones
        unordered_map<string, vector<string>> groups;  
        for (const string& s : strs){
            string key = s; 
            sort(key.begin(), key.end()); 
            
            // Add the original string 's' to the list associated with the unique key.
            // If the key doesn't exist, the map automatically creates an empty vector for it.
            groups[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto const& pair : groups) {
            result.push_back(pair.second);
        }
        return result;
    }
};