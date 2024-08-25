class Solution {
public:
int mod = 1e9+7;
# define ll long long int
int moduexpo(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ((ll)ans * (ll)a) %mod;
        }
        b = b / 2;
        a = ((ll)a * (ll)a)%mod ;
    }
    return ans;
} 
    vector<int> getFinalState(vector<int>& nums, int k, int& multi) {
           int n=nums.size();
           int mul = multi;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
        for(int i=0;i<n;i++) {
            pq.push({nums[i],i});
        } 

        while(mul>1 and k and ((ll)pq.top().first * (ll)mul) < mod) {
            int x = pq.top().first;  
            ll val = ((ll)x * (ll)mul);
            pq.push({ val ,pq.top().second});
               pq.pop();
            // cout<<val<<" "<<" "<<mul<<endl;
            k--;
        } 

        // [158205367,862774837,475528263,828321106]
        vector<int> ans(n);
  
        int minMul = moduexpo(mul,k/n);   
        while(pq.size()) {
        if(k%n) {
              ans[pq.top().second] = ( (ll)pq.top().first * (ll)mul)%mod; 
              ans[pq.top().second] = ( ans[pq.top().second] * (ll)minMul)%mod; 
            k--;
        } else {
                 ans[pq.top().second] = ( (ll)pq.top().first * (ll)minMul)%mod;
                //   cout<< (ll)pq.top().first  <<" " << minMul<<" "<<pq.top().second<<endl;
        }

        pq.pop(); 
 
        }  
       
        return ans;
    }
};