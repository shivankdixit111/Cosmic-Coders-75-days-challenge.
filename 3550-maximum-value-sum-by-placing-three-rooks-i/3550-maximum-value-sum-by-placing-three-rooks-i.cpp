   
 #include <bits/stdc++.h>
using namespace std;
#define in insert
#define ll long long
#define ff first 
#define ss second 
class Solution {
public:

    bool static cmp(pair<ll,pair<ll,ll>>& a,pair<ll,pair<ll,ll>>&b) {
        return a.first>b.first;
    }
    
    long long maximumValueSum(vector<vector<int>>& arr) {
        vector<pair<ll,pair<ll,ll>>> temp;
        int n=arr.size(),m=arr[0].size(),maxi=INT_MIN;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                temp.push_back({arr[i][j],{i,j}});
                maxi=max(maxi,arr[i][j]);
            }
        }
        auto arr1=temp;
        sort(temp.begin(),temp.end(),cmp);
        long long mini= LONG_MAX;
        
        ll ans=LONG_MIN;
        // for(auto it:temp) {
        //     cout<<it.ff<<" "<{it.ss.ff<<" "<<it.ss.ss}<<endl; 

          for(int i=0;i<temp.size();i++) {
             ll r1,c1,r2,c2,c3,r3,s1,s2,s3;
             r1=c1=r2=c2=r3=c3=-1;
             s1=s2=s3=-1;
             r1=temp[i].ss.ff,c1=temp[i].ss.ss,s1=temp[i].ff; 
            for(int j=i;j<temp.size();j++) {
                r2=temp[j].ss.ff,c2=temp[j].ss.ss,s2=temp[j].ff;
                if(ans>=(s1+s2+maxi)) continue;
                 for(int k=j+1;k<temp.size();k++) {
                        r3=temp[k].ss.ff,c3=temp[k].ss.ss,s3=temp[k].ff;  
                        if(r1!=r2 and r2!=r3 and c1!=c2 and c2!=c3 and c3!=c1 and r3!=r1) {
                            ans=max(ans,(ll)(s1+s2+s3));
                            break;
                        }
                 }
            }
        }

        return ans;
    }
};