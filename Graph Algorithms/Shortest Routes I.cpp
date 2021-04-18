#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

unordered_map<ll, vector<pii> > graph;
ll n, m;
const ll inf = 1e18;

void SSSP(ll u){
    vector<ll> dist(n+1, inf);
    dist[u] = 0;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, u});

    while(!pq.empty()){
        u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if(dist[u] != d) continue;

        for(auto x: graph[u]){
            ll v = x.first, w = x.second;
            if(d+w < dist[v]){
                dist[v] = d+w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout << dist[i] << " ";
}

int main(){
    cin >> n >> m;

    for(ll i = 0, x,y,w; i < m; i++){
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        //graph[y].push_back({x, w});
    }

    SSSP(1);
}