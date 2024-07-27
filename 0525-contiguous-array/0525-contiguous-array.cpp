class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0;
        map<int,int> mp;
        mp[0]=0;

        int n=nums.size(),sum=0;

        for(int i=1;i<=n;i++) {
           sum+=(nums[i-1]?1:-1);
           
        //    if(sum==0)  {
             if(mp[sum])
               ans=max(ans,(i-mp[sum]));
             if(sum==0) {
                 ans=max(ans,i-mp[sum]);
             }
        //    }
           if(mp[sum]==0 and sum!=0)
           mp[sum]=i;
        }
        return ans;
    }
};