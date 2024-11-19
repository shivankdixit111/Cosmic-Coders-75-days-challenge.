
// lc
#define vi vector<int>
#define vvii vector<vi>
#define ll long long int
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define vs vector<string>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define minpq(a) priority_queue<a,vi,greater<a>> pq
#define maxpq(a) priority_queue<a> pq 
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
  // calculating distance for root node 1
// if we go to let's say to node 2 then depth of all nodes of subtree of 2 decreases by 1
// depth of all nodes out of subtree of 2 increases by 1   
// so we just have to find the net change that will be   n - 2 * Size[2(it)] 
//(multiplied by 2 because Size is already present in n  + (n-Size[it]-> increment) - (Size[it]->decrement)

    int Size[100004];
    int n;
    void dfs(int  node, int par, int h, vi &ans, vvii &adj) {
        ans[node] = h;
        for(auto it:adj[node]) {
            if(it != par) { 
                dfs(it, node, h+1, ans, adj);
                ans[node] += ans[it];
                Size[node] += Size[it];
            }
        }
        Size[node] += 1;  
    }
    void dfs2(int node, int par, vvii &adj, vi &ans) {
        
        for(auto it:adj[node]) {
            if(it != par) {
                ans[it] = ans[node] + n - Size[it] - Size[it]; //increment of node outof 
                //subtree and decrement of nodes of subtree
                dfs2(it, node, adj, ans); 
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n1, vector<vector<int>>& edges) {
        n = n1; 
        vvii adj(n);
        for(auto it:edges) {
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
        }
        vi ans(n);
        dfs(0,-1,0,ans,adj);
        dfs2(0,-1,adj,ans);
        
        return ans;

    }
};