#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int j = 0; j < m; j++)
        cin >> b[j];

    sort(a, a+n);
    sort(b, b+m);

    int ans = 0;
    for(int i = 0, j = 0; i < n; i++){
        while(j < m && a[i] - b[j] > k)
            j++;
        if(j == m) break;
        if(abs(a[i] - b[j]) > k) continue;

        j++;
        ans++;
    }
    cout << ans;
}

