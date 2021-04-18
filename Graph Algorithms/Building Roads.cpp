#include <bits/stdc++.h>
 
using namespace std;
 

unordered_map<int, vector<int>> graph;
bool visited[100005];

void dfs(int u){
    if(visited[u]) return;
    visited[u] = true;
    for(auto x: graph[u]){
        dfs(x);
    }
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

    vector<int> res;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            res.push_back(i);
        }
    }
    cout << res.size()-1 << endl;

    if(res.size() > 1){
        for(int i = 1; i < res.size(); i++){
            cout << res[i] << " " << res[i-1] << endl;
        }
    }

}