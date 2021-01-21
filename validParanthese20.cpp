// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
// Example 4:

// Input: s = "([)]"
// Output: false
// Example 5:

// Input: s = "{[]}"
// Output: true
 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.



class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(i=='(' or i=='{' or i=='['){
                st.push(i);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char t=st.top();
                if(i==')'){
                    if(t=='('){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(i=='}'){
                    if(t=='{'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                } 
                else if(i==']'){
                    if(t=='['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                } 
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};