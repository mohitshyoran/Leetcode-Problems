Given a string s, find the length of the longest 
substring without repeating characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<int,int> freq;
        int i = 0, j = 0;
        while(i <= j && j < s.size()){
            freq[s[j]]++;
            while(i < j && freq[s[j]] > 1){
                freq[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
