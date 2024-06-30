class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
       int cnt=1,cnt2=1,tred=red,tblue=blue;
       bool b=false,r=false;
            red-=cnt;
            r=true;
            cnt++;
       while(true) {
          if(b) {
            if(red<cnt) break;
             red-=cnt;
             r=true;
             b=false;
          } else {
            if(blue<cnt) break;
            blue-=cnt;
            b=true;
            r=false;
          }
          cnt++;
       }
        
        red=tred,blue=tblue;
        cnt2=1;
        b=false,r=false;
            blue-=cnt2;
            b=true;
            cnt2++;
       while(true) {
          if(b) {
             if(cnt2>red) break;
             red-=cnt2;
             r=true;
             b=false;
          } else {
            if(cnt2>blue) break;
            blue-=cnt2;
            b=true;
            r=false;
          }
          cnt2++;
       }

       cnt--; cnt2--;

    //    cout<<cnt<<" "<<cnt2<<endl;

       return max(cnt,cnt2);
    }
};