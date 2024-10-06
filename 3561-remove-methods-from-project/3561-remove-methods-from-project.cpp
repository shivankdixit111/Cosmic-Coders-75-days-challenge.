
#include <bits/stdc++.h>
#pragma GCC optimize("O3") // O3 or we may time out :(
#define vi vector<int>
#define vvii vector<vi> 
#define umii unordered_map<int, int>  
#define all(x) x.begin(), x.end()  
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end() 
 
class Solution {
    private:
    void mark(int node, vvii &adj, vi &vis, vi &mp) {
    vis[node]=1;
    for(auto it:adj[node]) {
        if(!vis[it]) {
            if(mp[node]) mp[it]=1;
            mark(it,adj,vis,mp);
        }
    }
   }
   void dfs(int node, vvii &adj, vi &vis, vi &mp,int k) {
    vis[node]=1;
    for(auto it:adj[node]) { 
        if(!vis[it]) {
            if(mp[node]==0) mp[it]=0;
            dfs(it,adj,vis,mp,k);
            // vis[it]=0;
        }
     }
   }

public:
 
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    
          vector<int> mp(n,0);
          vi vis(n,0);
          vvii adj(n);
          for(auto it: invocations) {
            adj[it[0]].push_back(it[1]);   
          }
          
          mp[k]=1;
          mark(k,adj,vis,mp);
          rep(i,0,n) vis[i]=0;
          rep(i,0,n) { 
            if(!vis[i])
            dfs(i,adj,vis,mp,k); 
          }
          for(auto it:invocations) 
          {
              if(mp[it[0]]==0) mp[it[1]]=0;
          }
          for(auto it:invocations) 
          {
              if(mp[it[0]]==0) mp[it[1]]=0;
          }

          bool all = true;
          for(auto it:invocations) 
          {
             if(mp[it[0]] and !mp[it[1]]) all = false;
          }
 
          vi ans;
          if(!all) {  
              rep(i,0,n) ans.push_back(i);
              return ans;
          }
 
          rep(i,0,n) if(mp[i]==0) ans.push_back(i);
          return ans;
    }
};