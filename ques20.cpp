class Solution {
    public:
        bool isValid(string s) {
            // Stack to keep track of opening brackets
            stack<char> brackets;
            
            // Iterate through each character in the string
            for (char c : s) {
                // If it's an opening bracket, push to stack
                if (c == '(' || c == '{' || c == '[') {
                    brackets.push(c);
                } 
                // If it's a closing bracket
                else {
                    // If stack is empty, no matching opening bracket
                    if (brackets.empty()) {
                        return false;
                    }
                    
                    // Check if the top of stack matches the current closing bracket
                    char top = brackets.top();
                    
                    if ((c == ')' && top != '(') ||
                        (c == '}' && top != '{') ||
                        (c == ']' && top != '[')) {
                        return false;
                    }
                    
                    // Remove the matching opening bracket
                    brackets.pop();
                }
            }
            
            // Stack should be empty for all brackets to be matched
            return brackets.empty();
        }
    };