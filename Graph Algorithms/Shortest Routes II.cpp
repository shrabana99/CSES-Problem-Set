#include <bits/stdc++.h>
 
using namespace std;
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    long inf = 1e18+7;
    vector<vector<long>> a(n+1, vector<long> (n+1, inf));
 
    for(int i = 1; i <= n; i++ ) a[i][i] = 0;
 
    for(int i = 0; i < m; i++){
        long x, y, w;
        cin >> x >> y >> w;
        a[x][y] = min(a[x][y], w);
        a[y][x] = a[x][y];
    }
 
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++ ){
            for(int j = 1; j <= n; j++ ){
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
 
    while(q--){
        int x, y;
        cin >> x >> y;
        if(a[x][y] == inf)
            cout << "-1\n";
        else
            cout << a[x][y] << endl;
    }
}