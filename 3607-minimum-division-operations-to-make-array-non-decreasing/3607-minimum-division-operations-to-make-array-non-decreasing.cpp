class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int last = nums[n-1];
        int cnt=0;
        for(int i=n-2;i>=0;i--) {
            bool flag = false;
            if(nums[i] <= last) {
                last = nums[i];
                continue;
            }
            for(int j=2;j*j<=nums[i];j++) {
                if(nums[i]%j==0) {
                    int val1 = nums[i]/j;
                        int div = nums[i]/j;
                    int val2 = nums[i]/div;
                    if(val1 <= last) {
                        last = val1;
                        cnt++;
                        flag=true;
                        break;
                    }
                    if(val2 <= last) {
                        last = val2;
                        flag = true;
                        cnt++;
                        break;
                    }
                }
            }
            if(!flag) {
                return -1;
            }
        }
        return cnt;
    }
};