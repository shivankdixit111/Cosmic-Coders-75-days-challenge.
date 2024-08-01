class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto it:s) {
            if(st.empty()) st.push(it);
            else {
                if(st.top()=='(' and it==')') st.pop();
                else st.push(it);
            }
        }
        return st.size();
    }
};