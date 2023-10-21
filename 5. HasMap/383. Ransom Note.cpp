Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mag;
        for(auto ch: magazine)
            mag[ch]++;
        
        unordered_map<char,int> ran;
        for(auto ch: ransomNote)
            ran[ch]++;
        
        for(auto it = ran.begin(); it != ran.end(); it++){
            if(mag[it->first] < ran[it->first]) return false;
        }
        return true;
    }
};
