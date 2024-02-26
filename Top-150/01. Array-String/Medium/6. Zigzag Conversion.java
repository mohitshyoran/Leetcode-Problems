https://leetcode.com/problems/zigzag-conversion/submissions/1186737104/?envType=study-plan-v2&envId=top-interview-150

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

class Solution {
    public String convert(String s, int numRows) {
        if(numRows <= 1)   return s;

        String ans = "";
        String[] res = new String[numRows];
        Arrays.fill(res, "");

        int dir = -1;
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(j == 0 || j == numRows-1)    dir = dir*-1;

            res[j] += s.charAt(i);

            if(dir == 1)    j++;
            else j--;
        }

        for(int i = 0; i < numRows; i++){
            ans += res[i];
        }
        return ans;
    }
}


