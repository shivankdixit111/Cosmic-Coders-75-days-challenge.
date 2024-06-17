  int n;
  vector<int> fen; 

  void create(vector<int> &a) {
    fen.assign(n+1,0);
    for(int i=1 ; i<=n ; i++){
        fen[i]+= a[i];
        int p = i + (i&(-i));
        if(p<=n) fen[p]+=fen[i];
    }
  }

  void update(int i,int val) { 
    //    cout<<i<<" "<<val<<": ";
       while(i<=fen.size()) {
        //   cout<<i<<" ";
          fen[i]+=val;
          i = i + (i&(-i));  //update the value at 2th power
       }
   }

  int fensum(int i) {
      int s=0;
      while(i>0) {
         s+=fen[i];
         i = i - (i&(-i));  //finding the sum which is stored at 2th power then decrese it
      }
      return s;
  }

  int rangesum(int l,int r) {
    return fensum(r)-fensum(l-1);
  }
class Solution {
public:
   void check(int i,vector<int> &nums,vector<int> &a) {
        int n=nums.size();
        if(i<=0 or i>=n-1) return;

        if(a[i+1]==1) {
            if(nums[i]<=nums[i+1] or nums[i]<=nums[i-1]) {
                update(i+1,-1);
                a[i+1]=0;
            }
        } else {
            if(nums[i]>nums[i+1] and nums[i]>nums[i-1]) {
                update(i+1,1);
                a[i+1]=1;
            }
        }
 
   }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
          n=nums.size();
         fen.resize(n+1,0);
         vector<int> a(n+1,0);

         for(int i=1;i<n-1;i++) {
            if(nums[i]>nums[i-1] and nums[i]>nums[i+1]) a[i+1]++;
         }

         create(a);

         
         vector<int> ans;

         for(auto it:queries) {
             if(it[0]==1) {
                //find sum
                
                int l=it[1],r=it[2];
                l++; r++;  //1 based indexing
                ans.push_back(max(0,rangesum(l+1,r-1)));  //find sum of (l+1 to r-1)
             } else {
                //updation
                int idx=it[1],val=it[2];
                nums[idx]=val;
                 check(idx,nums,a);
                check(idx-1,nums,a);
                check(idx+1,nums,a);

             }
         }
         return ans;
    }
};