#include <bits/stdc++.h>

using namespace std;

const int maxN=2e5+5;
vector<int> g[maxN];

int height[maxN], dist[maxN];

void dfs1(int u, int p){
	for(auto x: g[u]){
		if(x == p) continue;
		dfs1(x, u);
		height[u] = max(height[u], height[x] + 1);
	}
}

void dfs2(int u, int p){
	int maxH1 = -1, maxH2 = -1;
	for(auto x: g[u]){
		if(x == p) continue;
		if(maxH1 < height[x]){
			maxH2 = maxH1;
			maxH1 = height[x];
		}
		else if(maxH2 <= height[x]){
			maxH2 = height[x];
		}
	}

	for(auto x: g[u]){
		if(x == p) continue;
		int maxH = height[x] == maxH1 ? maxH2 : maxH1;
		dist[x] = max(dist[u] + 1, maxH + 2);
		dfs2(x, u);
	}
}

int main(){
	int n;
	cin >> n;

	for(int i = 0, x, y; i < n-1; i++){
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs1(1, 0);

	dfs2(1, 0);

	for(int i = 1; i <= n; i++){
		//cout << height[i] << " " << dist[i] << "\n"; 
		cout << max(height[i], dist[i]) << " ";
	}

}