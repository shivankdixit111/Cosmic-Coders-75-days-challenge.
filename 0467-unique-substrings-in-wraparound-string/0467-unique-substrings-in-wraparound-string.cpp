class Solution {
public: 
    int findSubstringInWraproundString(string s) {
        int pans=1,ans=1;
        vector<int>  f(26,0);
        f[s[0]-'a'] = 1;
        
        for(int i =1;i<s.length();i++) {
            if((s[i-1]-'a'+1)%26 == (s[i]-'a')) pans++;
            else pans = 1;

            if( f[s[i]-'a'] < pans) {
                ans += pans - f[s[i]-'a'];
                f[s[i]-'a'] = pans;
            }
        }
        return ans;
    }
};