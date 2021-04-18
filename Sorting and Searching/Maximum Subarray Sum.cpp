#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    long a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long curMax = a[0], mxAll = a[0];
    for(int i = 1; i < n; i++){
        curMax = max(curMax + a[i], a[i]);
        mxAll = max(curMax, mxAll);
    }
    cout << mxAll;
}

