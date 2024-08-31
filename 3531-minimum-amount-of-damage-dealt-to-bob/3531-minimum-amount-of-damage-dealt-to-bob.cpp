#include<bits/stdc++.h>
#define ll long long int
class Solution {
public:

    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n= damage.size(); 
         
         vector<int> a(n);
         iota(a.begin(),a.end(),0);
         sort(a.begin(),a.end(), [&](int i,int j) {
             return damage[j] * 1LL * ceil(health[i]/double(power)) < damage[i] *1LL* ceil(health[j]/double(power));
         });
         
         int sum = accumulate(damage.begin(),damage.end(),0);
         int sum1 = sum;

         long long ans=0;
         for(int i=0;i<n;i++) { 
            int idx = a[i];
            long long val = sum * 1LL * ceil((double)health[idx]/power);
            ans +=val;
            sum-= damage[idx];
         }
         return  ans;
    }
};