#include <bits/stdc++.h>
 
using namespace std;
 
unordered_map<int, vector<int>> graph;
int color[100005];

bool isOddCycle(int u, int col){
    if(color[u]){
        return color[u] != col;
    }

    color[u] = col;
    for(auto v: graph[u]){
        if(isOddCycle(v, col == 1 ? 2: 1))
            return true;
    }
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
        if(!color[i]){
            if(isOddCycle(i, 1)){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout << color[i] << " ";
}