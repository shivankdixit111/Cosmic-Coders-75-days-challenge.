class Solution {
public:
   bool ispal(string s) {
      for(int i=0;i<=s.length()/2;i++) {
        if(s[i]!=s[s.length()-i-1]) return false;
      }
      return true;
   }
    void rec(int i, int n, string &s, vector<string> &temp, vector<vector<string>> &ans) {
        if(i>n) return;
        if(i==n) {
            ans.push_back(temp);
            return;
        }
         
         for(int j=1;i+j<=n;j++) {
            string sub = s.substr(i,j);
            if(ispal(sub)) {
                temp.push_back(sub);
                rec(i+j,n,s,temp,ans);
                temp.pop_back();
            }
         }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        rec(0,s.length(),s,temp,ans);
        return ans;
    }
};