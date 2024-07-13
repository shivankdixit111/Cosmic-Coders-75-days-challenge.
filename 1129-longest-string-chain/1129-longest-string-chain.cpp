class Solution {
public:
    bool check(string &s1,string& s2) {
        int cnt=1,i=0,j=0;
        if(s1.size()+1!=s2.size()) return false;
        while(j<s2.length()) {
           if(i<s1.length() and s1[i]==s2[j]) {
             i++;
             j++;
           } else { 
                 j++; 
           }
        }
        if(i==s1.length() and j==s2.length()) return true;
         
        return false;
    }
    
    static bool cmp(string &s1, string& s2) {
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        
        sort(words.begin(),words.end(),cmp);
        
        for(int i=0;i<n;i++) {
            for(int prev=0;prev<i;prev++) {
               if(check(words[prev],words[i]) and 1+dp[prev]>dp[i]) {
                   dp[i]=1+dp[prev];
               }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};