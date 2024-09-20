class Solution {
 long long int s[500001][2][2];
 const int mod = 1e9+7;

 void combine(int idx) {
    
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
           s[idx][i][j] = 0;
           
           for(int k=0;k<2;k++) {
             for(int l=0;l<2;l++) {
                if(k==0 or l==0) // we cann't select adjacent
                s[idx][i][j] = max( s[idx][i][j], s[2*idx+1][i][k] + s[2*idx+2][l][j] );
             }
           }
        }
    }
 }
//--------------------- Segment Tree ------------------------------------------------//
vector<int> Segtree;
void build(vector<int> &arr, int low, int end, int index)
{ // time complexity--> O(n)

    if (low == end)
    {
        s[index][1][1] = max(0,arr[low]);
        s[index][1][0] = s[index][0][1] = s[index][0][0] = 0;
        return;
    }

    int mid = (low + end) / 2;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    build(arr, low, mid, left);
    build(arr, mid + 1, end, right); 
    combine(index);
}

void pointupdate(int low, int high, int index, int pos, int value)
{ // time complexity--> O(log n)

    if (low == high)
    {
        s[index][1][1] = max(0,value);
        s[index][1][0] = s[index][0][1] = s[index][0][0] = 0;
        return;
    }
    int mid = (low + high) >> 1;

    if (pos >= low and pos <= mid)
        pointupdate(low, mid, 2 * index + 1, pos, value);
    else
        pointupdate(mid + 1, high, 2 * index + 2, pos, value);

    combine(index);
}
 
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        Segtree.resize(4*n,0);
        build(nums,0,n-1,0);
        
        int sum = 0;

        for(auto it:queries) {
            int pos = it[0];
            int val = it[1];

            pointupdate(0,n-1,0,pos,val);

            sum = ( sum % mod + s[0][1][1] %mod)%mod;  //value at index 0
        }

        for(int i=0;i<=500000;i++) {
            for(int j=0;j<2;j++) {
                for(int k=0;k<2;k++) s[i][j][k]=0;
            }
        }

        return sum;
    }
};