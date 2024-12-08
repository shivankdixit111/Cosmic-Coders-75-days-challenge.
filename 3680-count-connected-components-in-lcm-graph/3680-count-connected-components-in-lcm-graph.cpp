#define vi vector<int>
#define vvii vector<vi>
#define vpii vector<pair<int,int>>
#define pii  pair<int,int>
#define ll long long int
#define vs vector<string>
#define mii map<int, int>
#define umii unordered_map<int, int> 
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define pb push_back 
#define in insert
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define MAX(x) *max_element(x.begin(), x.end())
#define MIN(x) *min_element(x.begin(), x.end())
#define SUM(X) accumulate(X.begin(), X.end(), 0LL)
#define rev(a) reverse(a.begin(), a.end()); 
 
 

class Solution {
public:
   class DisjointSet { //tells whether u and v belong to same component in constant time O(1)--//
  public:
   vector<int> rank,parent,size;
    DisjointSet(int n) {
       rank.resize(n+1,0);
       parent.resize(n+1);
       size.resize(n+1,1);

       for(int i=0;i<=n;i++) parent[i]=i;
    
    }

    int findUlp(int node) {
        if(node==parent[node]) return node;

        return parent[node]=findUlp(parent[node]);
    }

    void findUnionByRank(int u,int v) {
        int u_ulp=findUlp(u);
        int v_ulp=findUlp(v);

        if(u_ulp==v_ulp) return;

        int urank=rank[u_ulp],vrank=rank[v_ulp];

        if(urank==vrank) {
            parent[v_ulp]=u_ulp;
            rank[u_ulp]++;
        } else if(urank>vrank) {
            parent[v_ulp]=u_ulp;
        } else {
            parent[u_ulp]=v_ulp;
        }
    }
    
    void findUnionBySize(int u,int v) {  //it stores the size as rank gets distorted while path compression
         int ulp_u=findUlp(u);
         int ulp_v=findUlp(v);

         if(ulp_u==ulp_v) return;

         if( size[ulp_u] > size[ulp_v] ) {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
         } else {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
         }
    }
 };
 vi divisor(int n)
{
    vi ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.pb(i);
            if (i != n / i)
            {
                ans.pb(n / i);
            }
        }
    }
    return ans;
}
    int countComponents(vector<int>& nums, int t) {
         vi nodes; int compo=0;
         for(auto it:nums) {
            if(it <= t) nodes.push_back(it);
            else compo++;
         }
         int m = nodes.size(); vi sm(t+1,-1);
         int i=0;
         for(auto it:nodes) {
            cout<<it<<" : ";
            for(auto d:divisor(it)) {
                if(sm[d]==-1 or nodes[sm[d]] > it) {
                    sm[d] = i;
                }
                // cout<<d<<" "<<sm[d]<<endl;
            }
            // cout<<endl;
            i++;
         }

         DisjointSet ds = DisjointSet(t);
         rep(i,0,m) {
            for(auto d: divisor(nodes[i])) {
                if(lcm( nodes[sm[d]], nodes[i]) <= t) {
                    // cout<<d<<" "<<sm[d]<<" "<<nodes[sm[d]]<<" "<<nodes[i]<<endl;
                    ds.findUnionByRank(nodes[sm[d]], nodes[i]);
                }
            }
         }
         umii mp;
         for(auto it:nodes) {
            mp[ds.findUlp(it)]++;
         } 
         compo += mp.size();
         return compo;
    }
};