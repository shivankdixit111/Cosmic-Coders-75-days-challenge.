class Solution {
public: 
    unordered_map<string,int> mp;
    bool rec(string s1, string s2) {
        int n = s1.length();
        if(s1==s2) return true;
         bool flag = false;

         string key = s1 + "#" + s2;
         
         if(mp.find(key)!=mp.end()) return mp[key];
         
         for(int len=1;len<=n-1;len++) {
            bool swap = rec(s1.substr(0,len),s2.substr(n-len,len)) and rec(s1.substr(len,n-len),s2.substr(0,n-len));
            bool notswap = rec(s1.substr(0,len),s2.substr(0,len)) and rec(s1.substr(len,n-len),s2.substr(len,n-len));

            if(swap or notswap) {
                flag = true;
                break;
            }
         }
         return mp[key] = flag;
    }
    bool isScramble(string s1, string s2) { 
        return rec(s1,s2);
    }
};