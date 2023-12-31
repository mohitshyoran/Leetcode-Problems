Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false


//Same approach as isomorphic string
  
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> mp1;
        unordered_map<string, int> mp2;

        int i = 0, n = pattern.size();
        stringstream ss(s);
        string word;

        while(ss>>word){
            if(i == n)  return false;
            char ch = pattern[i];
            if(mp1[ch] != mp2[word])  return false;
            mp1[ch] = mp2[word] = i+1;
            i++;
        }
        return i == n;
    }
};

