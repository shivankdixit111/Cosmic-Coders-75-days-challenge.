class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi = 0, n = s.length();
        stack<int> st;
        st.push(-1);

        for(int i=0;i<n;i++) {
           if(s[i]=='(') st.push(i);
           else st.pop();

           if(st.size()) {
             maxi = max(maxi, i-st.top());
           } else {
              st.push(i);
           }
        }
        
        return maxi;
    }
};