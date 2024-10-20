class Solution {
public:
    void rec(int i,int n, string &s, vector<string> &wordDict, vector<string> &temp, vector<vector<string>> &ans) {
        if(i==n) {
            ans.push_back(temp);
            return;
        }
        
        for(auto it:wordDict) {
            string sub = s.substr(i,it.length()); 
            if(sub==it) {
                temp.push_back(sub);
                rec(i+it.length(),n,s,wordDict,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         int n = s.length();
         vector<string> temp;
         vector<vector<string>> ans;
         rec(0,n,s,wordDict,temp,ans);
         
         vector<string> ans1; 
         
         for(auto it:ans) {
            string t=""; 
            for(auto i:it) t += i + " ";
            t.pop_back();
            ans1.push_back(t);
         }
         return ans1;
    }
};