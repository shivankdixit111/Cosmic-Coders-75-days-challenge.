class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char> st;
        int n=s.length();
        vector<int> vis(n+1,0);

        for(int i=0;i<s.length();i++) {
            if(st.empty() or s[i]=='(') {
                if(st.empty()) vis[i]=1;
                st.push(s[i]);
            }
            else {
               if(st.size()==1) vis[i]=1;
               st.pop();
            }
        }
        for(int i=0;i<n;i++) {
            if(vis[i]==1) continue;
            ans+=s[i];
        }
        return ans;
    }
};