/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 
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

class Solution {
public:
    int maxi=0;
    umii mp;
    int rec(TreeNode* root) {
        if(!root) return 0;
        

        int l = rec(root->left);
        int r = rec(root->right);

        if(l!=r) return -1; 
        mp[l+r+1]++;
        maxi = max(maxi,max(l,max(r,l+r+1)));
        return (1 + l + r);
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
       int dummy= rec(root);
       vector<int> psum;
       for(int i=1;i<=maxi;i++) {
           psum.push_back( mp[i]);
       }
 
       
       reverse(psum.begin(),psum.end());
       
       for(int i=1;i<maxi;i++) psum[i]+=psum[i-1];
        

       auto it = lower_bound(all(psum),k)-psum.begin(); 
         if(it==maxi) return -1;
        //  cout<<it<<" "<<maxi<<endl;
       return (maxi-it)==0?-1:(maxi-it);

    }
};