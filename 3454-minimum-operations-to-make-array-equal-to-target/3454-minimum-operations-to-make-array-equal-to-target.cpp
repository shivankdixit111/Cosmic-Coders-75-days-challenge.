#define ff first
#define ss second
class Solution {
public:
     bool issame(vector<int> a,vector<int> &b) {
         if(a.size()!=b.size()) return false;
         int n=a.size();
     for(int i=0;i<n;i++) {
         if(a[i]!=b[i]) return false;
     }
     return true;
    } 
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
         vector<pair<int,int>> arr;  //0 dec 1- inc
            int i=0,n=nums.size();
         
        for(int i=0;i<n;i++) {
            if(nums[i]>target[i]) arr.push_back({nums[i]-target[i],0});
            else if(nums[i]<target[i]) arr.push_back({target[i]-nums[i],1});
            else arr.push_back({0,-1});
        }
        
         i=0;
        
        if(arr.empty()) return 0;

         n=arr.size();
         long ans=0;
         while(i<n) {
             int sum=0,cnt=0,mini=0;
             while(i<n-1 and ((arr[i].ss==1 and arr[i+1].ss==1) or (arr[i].ss==0 and arr[i+1].ss==0))) {
                 if(arr[i].ff>mini) {
                    sum+=arr[i].ff-mini;
                    mini=arr[i].ff;
                 } else {
                    mini=arr[i].ff;
                 }
                 i++;
                 cnt++;
             } 
             if(cnt and i>0) {
                if(arr[i].ff>mini and arr[i-1].ff<arr[i].ff) {
                    sum+=arr[i].ff-mini;
                    mini=arr[i].ff;
                 } else {
                    mini=arr[i].ff;
                 }
             }
             if(cnt==0) sum=arr[i].ff;

             cout<<sum<<" ";
             ans+=sum;
             i++;
         }
         cout<<endl;
        return ans;
    }
};