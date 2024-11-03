class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int i=0,maxi = INT_MIN;
        while(i<n) {
            bool g = false,s=false;
            int j=i,cnt=1;
            while(j<n-1) {
                if(!g and !s) {
                    if(arr[j]>arr[j+1]) g = true;
                    else if(arr[j]<arr[j+1]) s = true;
                    else break;
                    cnt++;

                } else {
                    if(g and arr[j]<arr[j+1]) g=false,s=true,cnt++;
                    else if(s and arr[j]>arr[j+1]) s=false,g=true,cnt++;
                    else break;
                }
                j++;
            }
            maxi = max(maxi,cnt);
            i++;
        }  
        return maxi;
    } 
};