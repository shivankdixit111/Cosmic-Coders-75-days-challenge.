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
#define rev(a) reverse(a.begin(), a.end()) 


class Segtree{
    public:
    vector<int> st,lazy;
    
    Segtree(int n) {
        st.resize(4*n);
        lazy.resize(4*n,-1);
    }

    void build(vi &arr, int low, int high, int idx) {
         if(low==high) {
            st[idx] = arr[low];
            return;
         }

         int mid = (low+high)>>1;
         build(arr, low, mid, 2*idx+1);
         build(arr, mid+1, high, 2*idx+2);

         st[idx] = max(st[2*idx+1] , st[2*idx+2]);
    }
    
    void push(int node) {
        if(lazy[node]!=-1) {
            st[2*node+1] = st[2*node+2] = lazy[node];
            lazy[2*node+1] = lazy[2*node+2] = lazy[node];
            lazy[node]=-1;
        }
    } 
 

    void rangeUpdate(int low,int high, int idx, int l, int r, int val) {
          
         if(low>=l and high<=r)  {         //complete overlap
            lazy[idx] = val;
            st[idx] = val;
            return;
         }
         
         if(high<l or low>r) return;     // if range lies outside 

         push(idx);
         int mid = (low+high)>>1;
         rangeUpdate(low,mid,2*idx+1,l,r,val);
         rangeUpdate(mid+1,high,2*idx+2,l,r,val);

         st[idx] = max(st[2*idx+1] , st[2*idx+2]);
    }  
  
    
    int query(int low,int high, int idx, int l, int r) { 
         if(low>=l and high<=r)  return st[idx];     //complete overlap  
         if(high<l or low>r) return 0;     // if range lies outside 

         push(idx);
         int mid = (low+high)>>1;
         int left = query(low, mid, 2*idx+1, l, r);
         int right = query(mid+1, high, 2*idx+2, l, r);

         return max(left,right);
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        set<int> sortedCord;
        vi ans; umii idx;
        for(auto it: positions) {
            sortedCord.insert(it[0]);
            sortedCord.insert(it[1] + it[0] - 1);
        }
        int compressedIdx=0;
        for(auto it: sortedCord) {
            idx[it] = compressedIdx;
            compressedIdx++;
        }
        n = compressedIdx;
        Segtree seg(n);

        for(auto it: positions) {
           int l = idx[it[0]];
           int r = idx[it[1] + it[0]-1];
 
           int maxInLtoR = seg.query(0,n-1,0,l,r);
           seg.rangeUpdate(0,n-1,0,l,r, maxInLtoR + it[1]); 
           int temp = seg.query(0,n-1,0,0,n-1);
           
           ans.pb(temp);
        }
        return ans;
    }
};