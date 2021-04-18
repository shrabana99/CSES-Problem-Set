#include <bits/stdc++.h>

using namespace std;

const int maxN=2e5+5, maxM = 30;
vector<int> g[maxN];

int tin[maxN], tout[maxN], level[maxN], dp[maxN][maxM];
int timer = 0;

void dfs(int u, int p){
	tin[u] = ++timer;
	dp[u][0] = p;

	for(int i = 1; i < maxM; i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];
	}

	for(auto x: g[u]){
		if(x != p) {
			level[x] = level[u] + 1;
			dfs(x, u);
		}
	}

	tout[u] = ++timer;
}

bool is_ancestor(int p, int u){
    return tin[p] < tin[u] && tout[u] < tout[p];
}

int lca(int u, int v)
{
	if(u == v) return 0;
    if (is_ancestor(u, v))
        return level[v] - level[u];
    if (is_ancestor(v, u))
        return level[u] - level[v];

    int a = u; 
    for (int i = maxM-1; i >= 0; --i) {
        if (!is_ancestor(dp[u][i], v)){
            u = dp[u][i];
        }
    }
    u = dp[u][0];
    return level[v] - level[u] + level[a] - level[u];
}

int main(){
	int n, q;
	cin >> n >> q;

	for(int i = 0, x, y; i < n-1; i++){
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, 1);

	while(q--){
		int a, b;
		cin >> a >> b;

		cout << lca(a, b) << endl;
	}

}