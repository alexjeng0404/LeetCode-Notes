class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(128, 0);
        
        // Count characters in t
        for (char c : ransomNote) {
            cnt[c]++;
        }
        // Compare with magazine
        for (char m : magazine){
            if (cnt[m]>0) cnt[m] -= 1;
        }
        
        for (char c : ransomNote) {
            if (cnt[c]!=0) return false;
        }
        return true;
    }
};