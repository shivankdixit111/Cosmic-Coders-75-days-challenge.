#define ll long long int
class Solution {
public:
    
    int rec(int stair, int jump, int prev, map<pair<ll,pair<ll,ll>>,ll> &mp , int k){
        int ans=0;
        if(stair> k+1) return 0;

        if(mp.count({stair,{jump,prev}})) return mp[{stair,{jump,prev}}];

         ans = rec(stair+(1 << jump),jump+1,0,mp,k) + (stair==k);

        if(!prev and stair>=1)
        ans += rec(stair-1,jump,1,mp,k);
        
        return mp[{stair,{jump,prev}}] = ans;
    }
    int waysToReachStair(int k) {
        map<pair<ll,pair<ll,ll>>,ll> mp;
        return rec(1,0,0,mp,k);
    }
};