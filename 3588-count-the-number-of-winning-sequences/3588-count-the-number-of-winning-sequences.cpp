class Solution {
public:
    bool a(char f, char s) {
        if(f==s) return false;
         if(f=='E' and s=='F') return true;
         if(f=='F' and s=='W') return true;
         if(f=='W' and s=='E') return true;
         return false;
    }
    bool b(char f, char s) {
        if(f==s) return false;
        if(!a(f,s)) return true;
        return false;
    }
    const int mod = 1e9+7;
    vector<vector<vector<int>>> dp;
    int rec(int i,char prev,string &s,int alice,int bob) {
        if(i==s.length()) {
                if(alice<bob) {
                    return 1;
                }
                return 0;
        } 
        if(dp[i][prev-'A'][bob-alice+1e3]!=-1) return dp[i][prev-'A'][bob-alice+1e3];
        
        int ans=0;
        //e 
        if(prev!='E')
        ans= (ans % mod + rec(i+1,'E',s,alice+a('E',s[i]),bob+b('E',s[i])) % mod)%mod;
        //f
        if(prev!='F')
        ans= (ans % mod + rec(i+1,'F',s,alice+a('F',s[i]),bob+b('F',s[i])) % mod)%mod;
        //w
        if(prev!='W')
        ans= (ans % mod + rec(i+1,'W',s,alice+a('W',s[i]),bob+b('W',s[i])) % mod)%mod;

        // cout<<i<<" "<<ans<<endl;

         return  dp[i][prev-'A'][bob-alice+1e3] = ans;
    }
    int countWinningSequences(string s) {
        int n = s.length();
        dp.resize(n+1,vector<vector<int>>(26,vector<int>(2001,-1)));
        return rec(0,'A',s,0,0);
    }
};