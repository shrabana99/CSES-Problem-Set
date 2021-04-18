#include <bits/stdc++.h>

using namespace std;

const int maxN=2e5+5, maxM = 30;
vector<int> g[maxN];

int  ans[maxN], level[maxN], dp[maxN][maxM];

void dfs(int u, int p){
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
}

int ancestor(int u, int k) {
    for (int i = 0; i < maxM; i++) 
        if (k & (1 << i)) 
            u = dp[u][i];
    return u;
}

int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);

    u = ancestor(u, level[u] - level[v]); 
    if (u == v) return u;
    for (int i = maxM - 1; i >= 0; i--){
        if (dp[u][i] != dp[v][i])
            u = dp[u][i], v = dp[v][i];
    }
    return dp[u][0];
}

void dfs1(int u, int p) {
	for (int v : g[u]) {
		if (v == p) continue;
		dfs1(v, u);
		ans[u] += ans[v];
	}
}

int main(){
	int n, q;
	cin >> n >> q;

	for(int i = 0, x, y; i < n-1; i++){
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, 0);

	while(q--){
		int a, b;
		cin >> a >> b;
		int m = lca(a, b); // cout << m << endl; 

		ans[a]++, ans[b]++, ans[m]--, ans[dp[m][0]]--;
	} 

	dfs1(1, 0);

	for(int i = 1; i <= n; i++) cout << ans[i] << " ";

}