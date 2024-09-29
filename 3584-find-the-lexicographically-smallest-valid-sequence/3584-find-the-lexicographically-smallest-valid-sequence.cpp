class Solution {
public:
    vector<int> validSequence(string s, string t) {
        int n = s.length(), m = t.length();
          bool flag= true;
          int i=n-1,j=m-1;
          vector<int> dp(n+1);

          while(j>=0 and i>=0) {
              dp[i] = j;
            if(s[i]==t[j]) {
                j--;
            }
            i--;
          }
          vector<int> ans,temp;
          for(int i =0,j=0;j<m and i<n; i++) {
            if(s[i]==t[j]) {
                 ans.push_back(i);
                 j++;
            } else if(flag and dp[i]<=j) {
                ans.push_back(i);
                j++;
                flag = false;
            }
          }
          for(auto it:ans) cout<<it<<" ";
          cout<<endl;

          return (ans.size()==m ?ans: temp);
    }
};
