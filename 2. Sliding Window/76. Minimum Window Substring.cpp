Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

// Approach 
// store frequency of both string in two map
// start sliding on bigger string , increase counter if current character is needed to complete string(check it by freq map)
// shrink window from left based on counter 



class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> FT,FS;
        // store freq of pattern
        for(auto ch: t){
            FT[ch]++;
        }
        
        int count = 0;
        int minLen = INT_MAX, start = 0, end = 0;
        // start window
        int i = 0, j = 0;
        while(j < s.size()){
            char ch = s[j];
            FS[ch]++;
            // expand window to right and increase count if necessary
            if(FS[ch] <= FT[ch]){
                count++;
            }
            // if pattern fount shrink window from left
            if(count == t.size()){
                while(FS[s[i]] > FT[s[i]]){
                    FS[s[i]]--;
                    i++;
                }
                int len = j - i + 1;
                if(minLen > len){
                    minLen = len;
                    start = i;
                    end = j;
                }
            }
            j++;
        }
        if(minLen == INT_MAX)   return "";
        return s.substr(start, minLen);
    }
};
