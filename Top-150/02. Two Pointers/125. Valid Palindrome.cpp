A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

class Solution {
public:
    bool isAphaNumeric(char ch){
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
    bool isSame(char ch1, char ch2){
        return (tolower(ch1) == tolower(ch2));
    }
    bool isPalindrome(string s) {

        int l = 0, r = s.size()-1;
        
        while(l <= r){
            while(l < s.size() && !isAphaNumeric(s[l]))    l++;
            while(r >= 0 && !isAphaNumeric(s[r]))    r--;
            if(l > r)   return true;
            if(!isSame(s[l], s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};


