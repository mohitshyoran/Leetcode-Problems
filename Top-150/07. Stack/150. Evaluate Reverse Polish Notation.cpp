You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.
Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 
Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        string operators = "+-*/";
        for(auto token : tokens){
            if(operators.find(token) == std::string::npos){
                st.push(stoi(token));
            }
            else{
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int res;
                switch(token[0]){
                    case '+': res = op2 + op1;
                                break;
                    case '-': res = op2 - op1;
                                break;
                    case '/': res = op2 / op1;
                                break; 
                    case '*': res = op2 * op1;
                                break;            
                }
                st.push(res);
            }
        }
        return st.top();
    }
};
