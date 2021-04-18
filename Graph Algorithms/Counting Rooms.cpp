#include <bits/stdc++.h>
 
using namespace std;

int vis[1001][1001];
char a[1001][1001];
int n, m;

void dfs(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '#' || vis[i][j]) return;

    vis[i][j] = 1;
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && a[i][j] != '#'){
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans;
}

