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
            for(int j=1;j<accounts[i].size();j++) {
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()) {
                    mp[mail]=i;
                } else {
                    findUnionBySize(i,mp[mail]); 
                }
            }
        }
        map<int,vector<string>> mp1;
        
        for(auto it:mp) {
            int ulp=findUlp(it.second);
            string mail=it.first;
            mp1[ulp].push_back(mail);  //storing all the mails
        }

        for(int i=0;i<n;i++) {
            if(mp1[i].size()) { 
                vector<string> temp=mp1[i];
                temp.push_back(accounts[i][0]); //pushing the name
                reverse(temp.begin(),temp.end());
                sort(temp.begin()+1,temp.end());
                ans.push_back(temp);
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};