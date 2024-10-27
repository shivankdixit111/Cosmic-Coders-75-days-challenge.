    // lc
    #define vi vector<int>
    #define vvii vector<vi>
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
 
 struct TrieNode{
     struct TrieNode* child[26];
     string s = "";
 
    TrieNode() {
        rep(i,0,26) { 
            child[i]=NULL;
        }
    }
  };
 
  TrieNode *root;
 
  void insertString(string str) {
 
    TrieNode* curr=root;
     
     for(int i=0;i<str.length();i++) {
         if(curr->child[str[i]-'a']==NULL) {
             curr->child[str[i]-'a'] = new TrieNode();
         }
         curr=curr->child[str[i]-'a'];
     }
 
     curr->s = str; 
  }
 

class Solution {
public:
     vector<string> ans;
    void search1(TrieNode* curr, TrieNode* temp) {
         if(curr->s!="" and temp->s!="") {
            ans.push_back(curr->s);
            curr->s = "";
         }
         if(temp->s!="") {
            search1(curr,root);
         }
         

         for(int i=0;i<26;i++) {
            if( curr->child[i] and temp->child[i] ) {
                search1(curr->child[i], temp->child[i]);
            }
         }
    }
    void search(TrieNode* curr) {
         if(curr->s!="") {
            search1(curr,root);
         }
         
         // go on every link
         for(int i=0;i<26;i++) {
             if(curr->child[i]!=NULL) search(curr->child[i]);
         }
    }
      
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
           root=new TrieNode();          
            rep(i,0,words.size()) { 
        
                //inserting dictionay word to a trie data structure
                insertString(words[i]);
            }
 
            
            TrieNode* curr = root;
            search(curr);
          
            return ans;
    }
};