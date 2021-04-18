#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, sum;
    cin >> n >> sum;

    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    int ans = n; // assuming all children sit seperately 
    for(int i = 0, r = n; i < n; i++){ // for each child_i, try to find the furthest child_r st a[i] + a[r] <= sum
        // then we can make them sit together and decrement the ans by 1
        /*
        2 2 3 ....... 6 7 7 ........
        2 l                        r (find 2's partner in the range l to r)
          2 l           r
            3 l       r

        */
        // r indicating previous child's partner(or not), so decrement it for current child
        // l will be next to i, ie i+1

        int l = i+1;
        r--; 
        if(l > r) // invalid range
            continue;

        while(l <= r){
            int md = (l+r)/2;
            if(a[md]+a[i] <= sum)
                l = md + 1;
            else 
                r = md - 1;
        } 
        if(i == r) // child and its partner has to be different 
            continue;

        ans--;
        //cout << i << " " << r << endl;
    }
    cout << ans;
}

