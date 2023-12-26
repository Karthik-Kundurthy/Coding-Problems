// practicing stack
// C++ chars
// for each loop
class Solution {
public:
    bool isValid(string s) {
        
        if (s.size() % 2 == 1) {
            return false;
        }
        
        std::stack<char> stack;
        
        
        for (char c: s) {
            if (c == '(' ||c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.empty()) {
                    return false;
                }
                
                char open = stack.top();
                stack.pop();
                
                if ((open == '(' && c != ')') || (open == '[' && c != ']')|| (open == '{' && c != '}')) {return false;}
            }
        }
        
        return stack.empty();
        
        
    }
};