#include <stack>

// We utilize a stack in this because when we see an opening bracket (which is (, [, or {), the next symbol should be its closing bracket.
// Therefore, we can use a LIFO structure to match our symbols.

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketMatch;

        for (char symbol : s) { // For each character in our string:
            
            // Push to stack if it's an opening bracket
            if (symbol == '(' || symbol == '[' || symbol == '{') bracketMatch.push(symbol); 
            
            // If the symbol is a closing bracket..
            if (symbol == ')') { 
                if (bracketMatch.empty() || bracketMatch.top() != '(') return false; // If the top isn't a matching opening bracket, it's not a valid parantheses.
                bracketMatch.pop(); // Else, we can pop the pair.
            } else if (symbol == ']') { // Repeat for each closing bracket type...
                if (bracketMatch.empty() || bracketMatch.top() != '[') return false;
                bracketMatch.pop();
            } else if (symbol == '}') {
                if (bracketMatch.empty() || bracketMatch.top() != '{') return false;
                bracketMatch.pop();
            }

            // We can ignore any other symbols.
        }

        // If there's still lingering symbols, then we will return false, since it was never matched. 
        // Otherwise, an empty stack means we have a valid set of parenthesis
        return bracketMatch.empty(); 
    }
};