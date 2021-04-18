#include <bits/stdc++.h>
 
using namespace std;
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> graph;
    bool vis[n+1];
    memset(vis, false, sizeof(vis));

    for(int i = 0, x, y; i < m; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int par[n+1];
    memset(par, -1, sizeof(par));
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()){
        int x = q.front(); q.pop();

        for(auto y: graph[x]){
            if(!vis[y]){
                q.push(y);
                vis[y] = true;
                par[y] = x;
            }
        }
    }

    if(vis[n]){
        vector<int> path;
        while(par[n] != -1){
            path.push_back(n);
            n = par[n];
        }
        path.push_back(1);
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        for(auto x: path) cout << x << " ";
    }
    else{
        cout << "IMPOSSIBLE";
    }

}