#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        long x, y;
        cin >> x >> y;
        long sq = max(x, y), res ;
        if(sq%2){
            if(sq == y)
                res = sq*sq - (x-1);
            else
                res = (sq-1)*(sq-1) + y;
        }
        else{
            if(sq == x)
                res = sq*sq - (y-1);
            else
                res = (sq-1)*(sq-1) + x;
        }
        cout << res << endl;
    }
}
 