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
#define rev(a) reverse(a.begin(), a.end());
const int mod = 1e9 + 7;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        // int i=0,j=0;
        // while(i<n and j<n) {
        //    while(i<n and nums[i]!=val) i++;
        //    if(j<n and i<n) {
        //      swap(nums[i],nums[j]);
        //      j++; i++;
        //    } 
        //    for(auto it: nums) cout<<it<<" ";
        //    cout<<endl;
        // }
        // cout<<j<<endl;
        // // for(int k=i;k<=j;k++) nums.pop_back();
        // return j;
        vector<int> temp;
        for(auto it: nums) if(it!=val) temp.push_back(it);
        rep(i,0,temp.size()) nums[i] = temp[i];
        rep(i,temp.size(),n) nums[i] = val;
        return temp.size();
    }
};