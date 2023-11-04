Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


class Solution {
public:
    bool dp[302];
    bool canBeFormed(string &s, unordered_set<string>& dict, int j){
        if(j == s.size())   return true;
        
        if(!dp[j]) return false;
    
        string str = "";
        while(j < s.size()){
            str += s[j];
            j++;
            if(dict.find(str) != dict.end()){
                bool flag = canBeFormed(s, dict, j);
                if(flag)    return true;
                else    dp[j] = false;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        memset(dp, true, sizeof(dp));
        return canBeFormed(s, dict, 0);
    }
};
