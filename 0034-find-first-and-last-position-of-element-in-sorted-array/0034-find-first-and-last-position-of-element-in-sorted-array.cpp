class Solution {
public:
    int f(vector<int> &arr, int target) {
        int ans=-1;
          int low=0,high = arr.size()-1;
       while(low<=high) {
            int mid = (low+high)/2;
 

            if(arr[mid]>=target) {
                ans = mid;
                high = mid-1;
            } else   {
                low=mid+1;
            }
        } 
        return ans;
    } 
    int s(vector<int> &arr, int target) {
        int ans=-1;
          int low=0,high = arr.size()-1;
        while(low<=high) {
            int mid = (low+high)/2;


            if(arr[mid] <= target) {
                   ans = mid;
                   low = mid+1;
            } else if(arr[mid]>target) {
                      high = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      
        
        vector<int> arr(2);
        arr[0] = f(nums,target);
        arr[1] = s(nums,target);
        if(arr[0]!=-1 and nums[arr[0]]!=target) arr[0]=-1;
        if(arr[1]!=-1 and nums[arr[1]]!=target) arr[1]=-1;
        return arr;
        // auto it = lower_bound(nums,)
    }
};