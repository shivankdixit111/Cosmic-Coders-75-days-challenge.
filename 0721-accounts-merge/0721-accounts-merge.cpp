class Solution {
public:
   static bool cmp(vector<string> &a,vector<string> &b) {
          return a[0][0]<b[0][0];
   }  
    vector<int> rank,parent,size; 
    void DisjointSet(int n) {
       rank.resize(n+1,0);
       parent.resize(n+1);
       size.resize(n+1,1);

       for(int i=0;i<=n;i++) parent[i]=i;
    
    }

    int findUlp(int node) {
        if(node==parent[node]) return node;

        return parent[node]=findUlp(parent[node]);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int> mp;
        set<int> st;
        vector<vector<string>> ans;
        int n=accounts.size();
        DisjointSet(n+1);
        for(int i=0;i<n;i++) {
            st.insert(i);
            for(int j=1;j<accounts[i].size();j++) {
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()) {
                    mp[mail]=i;
                } else {
                    findUnionBySize(i,mp[mail]); 
                }
            }
        }
        mp.clear();
        map<int,vector<string>> mp1;
        for(auto it:st) {
            int ulp=findUlp(it);
            if(ulp==it) { 
                 for(int i=1;i<accounts[it].size();i++) {
                   if(mp[accounts[it][i]]==0)
                    mp1[ulp].push_back(accounts[it][i]);
                    mp[accounts[it][i]]++;
                 }
            } else {
                for(int j=1;j<accounts[it].size();j++) {
                    if(mp[accounts[it][j]]==0)
                    mp1[ulp].push_back(accounts[it][j]);
                    mp[accounts[it][j]]++;
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(mp1[i].size()) {
                vector<string> temp=mp1[i];
                reverse(temp.begin(),temp.end());
                temp.push_back(accounts[i][0]);
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
        }
        for(int i=0;i<ans.size();i++) {
            sort(ans[i].begin()+1,ans[i].end());
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};