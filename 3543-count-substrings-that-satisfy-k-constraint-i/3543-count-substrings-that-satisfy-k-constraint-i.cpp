   
 #include <bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define revf(i,a,b) for(int i=b-1;i>=a;i--)
 
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
      int n=s.length(),cnt=0;

      rep(i,0,n) {
        string t="";
         int c1=0,c0=0;
        rep(j,i,n) { 
                    if(s[j]=='0') c0++;
                    else c1++;
           
              if(c1<=k or c0<=k) cnt++;
        }
      
      }   
      return cnt;
    }
};