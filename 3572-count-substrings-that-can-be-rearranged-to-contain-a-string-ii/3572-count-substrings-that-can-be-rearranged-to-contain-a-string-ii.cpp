 #define ll long long
class Solution {
public:
    long long validSubstringCount(string w, string t) {
        ll ans=0,n=w.length();
       vector<int> mp1(26,0),mp2(26,0);
        for(auto it:t) mp2[it-'a']++;

        auto ok=[&]() {
            for(int i=0;i<26;i++) {
                if(mp1[i]<mp2[i]) return false;
            }
            return true;
        };
        int i=0,j=0;
        while(j<n) {
            // if(mp2[w[j]-'a']) { 
                    mp1[w[j]-'a']++; 
            // }

            while(i<n and ok()) {
                ans += (n-j);
                mp1[w[i]-'a']--;
                i++; 
            }
            j++;
        }
        // cout<<ans<<endl;
        // j=i;
        // cout<<i<<endl;
        // mp1.clear();
        // while(j<n) {
        //     mp1[w[j]-'a']++;
        //     if(ok()) {
        //         cout<<j<<endl;
        //         ans += (n-j);
        //         mp1[w[i]-'a']--;
        //         i++; 
        //     }
        //     j++;
        // }
        return ans;
    }
};