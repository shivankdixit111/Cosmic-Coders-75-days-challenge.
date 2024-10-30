class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxi = INT_MIN , sum=0,s=0 , n = nums.size();
        for(int i=0;i<n;i++) {
           sum += (i*nums[i]);
           s += nums[i];
        } 
        maxi = max(maxi,sum);

        for(int i=n-1;i>=1;i--) {
            int newSum = sum + (s-nums[i]) - (n-1)*nums[i]; 
            maxi = max(maxi,newSum);
            sum = newSum;
        }

        return maxi;

    }
};