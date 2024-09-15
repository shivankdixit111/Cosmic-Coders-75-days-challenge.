
 struct TrieNode{
     struct TrieNode* child[26];
     bool isEnd;
 
    TrieNode() {
        for(int i=0;i<26;i++) {
            isEnd=false;
            child[i]=NULL;
        }
    }
  };
 
  TrieNode *root;
 
  void insertString(string str) {
 
    TrieNode* curr=root;
     
     for(int i=0;i<str.length();i++) {
         if(curr->child[str[i]-'a']==NULL) {
             curr->child[str[i]-'a']=new TrieNode();
         }
         curr=curr->child[str[i]-'a'];
     }
     curr->isEnd= true;
  }  

  int rec( int i, vector<int> &psum, vector<int> &dp ) {
     int n = psum.size();
     if(i==n) return 0;
     if(i>n) return 1e9;
     if(psum[i]==-1) return 1e9;

     if(dp[i]!=-1) return dp[i];

     int j= psum[i],ans=1e9;
     if(j==-1) return 1e9;
     for(int k=0;k<=j;k++) {
        ans = min(ans,1 + rec(i+k+1,psum,dp));
     }

     return dp[i]=ans;
  }
 

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        root=new TrieNode();
        int n = words.size(),m=target.length();
 
        for(int i=0;i<n;i++) { 
            string s= words[i];
    
            //inserting dictionay word to a trie data structure
            insertString(s);
        }
         int j=0;
         vector<int> psum(m,0);
        
         while(j<m) {
            int i=j,cnt=-1;
              TrieNode *temp = root;
            while(i<m) {
                if(temp->child[target[i]-'a']==NULL) {
                    // cout<<i<<" "<<target[i]<<" "<<cnt<<endl;
                    temp = root;
                    if(temp->child[target[i]-'a']!=NULL) 
                    temp = temp->child[target[i]-'a'];
                    break;
                } else {
                    cnt++;
                    temp = temp->child[target[i]-'a'];
        
                }
                i++;
            }
            psum[j] = cnt;
            j++;
         }

        //  if(cnt==m+1) {
        //     return -1;
        //  }

        //  return cnt;
        // for(auto it:psum) cout<<it<<" ";
        // cout<<endl;

        // int prev=0;
        // int i=0,cnt=0;
        // while(i<m) {
        //   if(prev>= psum[i]) {
        //      cnt++;
        //   } 
        //      prev--;
        //   prev= max(prev,psum[i]);
        //   i++;
        // }

        vector<int> dp(m+1,-1);
        int ans = rec(0,psum,dp);

        return ( ans== 1e9 ? -1 : ans );
 
 
    }
};