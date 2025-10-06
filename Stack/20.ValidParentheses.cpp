class Solution {
public:
    /**
     * @brief Determines if the input string contains valid, balanced parentheses using a Stack.
     * @param s The string containing parentheses.
     * @return true if the parentheses are valid, false otherwise.
     */
    bool isValid(string s) {
        // Stack: LIFO, push(item), pop(), peek(), isEmpty(), size()
        int n = s.length();
        if (n % 2 != 0) {
            return false;
        }
        stack<char> st;
        for (int i = 0; i < n; i++){
            char c = s[i];  // symbol

            // If it's an opening bracket, push to stack
            if ((c == '(') || (c == '[') || (c == '{')){
                st.push(c);
            }
            else{
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();

                if (!matches(top,c)) return false; 
            }
        }
        return st.empty();
    }
private:
    bool matches(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }
};