class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int> temp(n,0);
        int i=0;
        while(i<n) {
            bool flag=false;
            while(i<n-1 and (nums[i]==nums[i+1]-1)) {
                temp[i]=1;
                i++;
                flag=true;
            }
            if(k==1)
            temp[i]=1;
            i++;
        }
        vector<int> psum(n+1,0);
        psum[0]=temp[0];
        for(int i=1;i<n;i++) {
             psum[i]=psum[i-1]+temp[i];             
        }

        i=k-1;
        vector<int> ans;
        if(psum[i]==k) {
            ans.push_back(nums[i]);
        } else {
            if(i>0 and psum[i]==k-1 and temp[i]==0 and (nums[i]==nums[i-1]+1)) {
                ans.push_back(nums[i]);
            } else 
            ans.push_back(-1);
        }
        i++;

        while(i<n) {
            int sum= psum[i]-psum[i-k]; 
            if(sum==k) ans.push_back(nums[i]);
            else  {
                if(i>0 and sum==k-1 and temp[i]==0 and (nums[i]==nums[i-1]+1)) {
                    ans.push_back(nums[i]);
                } else  ans.push_back(-1);
            }
            i++;
        }
        return ans;
    }
};