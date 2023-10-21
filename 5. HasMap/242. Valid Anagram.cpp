Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(auto ch : s)    mp[ch]++;
        for(auto ch : t)    mp[ch]--;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second != 0) return false;
        }
        return true;
    }
};
