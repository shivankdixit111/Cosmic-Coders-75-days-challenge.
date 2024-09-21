
class Solution {
public:
   
vector<long long> Segtree;  

void pointupdate(int low, int high, int index, int pos, int value)
{ // time complexity--> O(log n)
    if (low == high)
    {
        Segtree[index] = value;
        return;
    }
    int mid = (low + high) >> 1;

    if (pos >= low and pos <= mid)
        pointupdate(low, mid, 2 * index + 1, pos, value);
    else
        pointupdate(mid + 1, high, 2 * index + 2, pos, value);

    Segtree[index] = max(Segtree[2 * index + 1] , Segtree[2 * index + 2]);
}

int query(int low, int high, int index, int l, int r)
{ // time complexity--> O(log n)
    // complete overlap       l........low.........high........r
    if (low >= l and high <= r)
        return Segtree[index];

    // disjoint
    if (l > high or r < low)
        return 0;

    int mid = (low + high) >> 1;
    int leftanswer = query(low, mid, 2 * index + 1, l, r);
    int rightanswer = query(mid + 1, high, 2 * index + 2, l, r);

    //   cout<<index<<" "<<leftanswer<<" "<<rightanswer<<endl;
    return max(leftanswer , rightanswer);
}
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> temp;
        int n = 1e5;
 
        Segtree.resize(3*n,0);  
       
        set<int> st;
        st.insert(0);
        st.insert(n);
        pointupdate(0,n-1,0,0,n);
 
      
        for(auto it:queries) {
            int type=it[0];
            if(type==1) { 
               int x= it[1];
               auto it1 = st.lower_bound(x);
               it1--;
               auto it2 = st.upper_bound(x);

               int l = *it1;
               int r = *it2;
               
               pointupdate(0,n-1,0,l,x-l);
               pointupdate(0,n-1,0,x,r-x);
               st.insert(x);
            } else {
               int x = it[1], sz = it[2];
               auto it1 = st.lower_bound(x);
               it1--;

               int l = *it1;
               int ans = max(query(0,n-1,0,0,l-1), x-l);
 
               temp.push_back(ans>=sz);
            } 
         
        }

        //0-1 1-99  1-10 11-89  1-3  4-7  4-4  8-3

         return temp;
    }
};