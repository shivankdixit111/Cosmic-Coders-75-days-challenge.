class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<int,int> mp1,mp2;
        int n=s.length();

        for(int i=0;i<n;i++) {
            if(mp1[s[i]-'a']==0) {
                mp1[s[i]-'a']=(t[i]-'a'+1); 
                if(mp2[t[i]-'a']==0)
                mp2[t[i]-'a']=(s[i]-'a'+1);
                else {
                   if(mp2[t[i]-'a']!=(s[i]-'a'+1)) return false;
                }
            } else {
                if(mp1[s[i]-'a']!=(t[i]-'a'+1)) return false; 
            }
        }
        return true;
    }
};