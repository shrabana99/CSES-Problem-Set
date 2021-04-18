#include <bits/stdc++.h>
 
using namespace std;
 
unordered_map<int, vector<int>> graph;
int vis[100005];
vector<int> path;
 
bool isCycle(int u, int p){
    if(vis[u] == 2) return false;
    if(vis[u] == 1) {
        path.push_back(u);
        return true;
    }
    vis[u] = 1;
    path.push_back(u);
    for(int v: graph[u]){
        if(v == p) continue;
        if(isCycle(v, u)) return true;
    }
    vis[u] = 2;
    path.pop_back();
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
 
    for(int i = 0, x, y; i < m; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
 
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(isCycle(i, 0)){
                vector<int> res;
                for(int i = path.size()-1; i >= 0; i--){
                    res.push_back(path[i]);
                    if(i != path.size()-1 && path[i] == path.back())
                        break;
                }
                cout << res.size() << endl;
                for(int x: res) cout << x << " ";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}