#include <bits/stdc++.h>

using namespace std;

const int maxN=2e5+5, maxM = 30;
vector<int> g[maxN];

int tin[maxN], tout[maxN], dp[maxN][maxM];
int timer = 0;

void dfs1(int u, int p){
	tin[u] = ++timer;
	dp[u][0] = p;

	for(int i = 1; i < maxM; i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];
	}

	for(auto x: g[u]){
		if(x != p) 
			dfs1(x, u);
	}

	tout[u] = ++timer;
}


int main(){
	int n, q;
	cin >> n >> q;

	for(int i = 0, x, y; i < n-1; i++){
		cin >> x;
		y = i+2; 
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs1(1, 0);

	while(q--){
		int x, k;
		cin >> x >> k;

		for(int i = maxM-1; i >= 0; i--){
			if((k & (1 << i))) { 
				x = dp[x][i];
			}
		}

		cout << (x == 0 ? -1: x) << "\n";

	}

}