class Solution {
public:
    
    int minimumDifference(vector<int>& nums) {
          int n=nums.size(),N=nums.size()/2,sum=0;
          for(auto it:nums) sum+=it;
          vector<vector<int>> left(N+1),right(N+1);

          for(int mask=0;mask<(1<<N);mask++) {
            int leftsum=0,rightsum=0,idx=0;

               for(int i=0;i<N;i++) {
                  if(mask&(1<<i)) {
                     idx++;
                     leftsum+=nums[i];
                     rightsum+=nums[i+N];
                  }
               }

               left[idx].push_back(leftsum);
               right[idx].push_back(rightsum);
          }

          for(int i=0;i<=N;i++) sort(right[i].begin(),right[i].end());

          int ans = min ( abs(sum-2*left[N][0]), abs(sum-2*right[N][0]) ) ;

          for(int idx=1;idx<N;idx++) {
             for(auto a:left[idx]) {
                 int b=(sum-2*a)/2;
                 vector<int> &b_array=right[N-idx];
                 auto it=lower_bound(b_array.begin(),b_array.end(),b);
                 if(it!=b_array.end()) {
                     ans=min(ans,abs(sum-2*(a+*(it))));
                 }
             }
          }

          return ans;
    }
};