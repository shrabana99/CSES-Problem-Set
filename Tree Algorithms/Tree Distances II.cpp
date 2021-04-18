#include <bits/stdc++.h>

using namespace std;

const int maxN=2e5+5;
vector<int> g[maxN];

long heightSum[maxN], child[maxN], distSum[maxN];

void dfs1(int u, int p){
	child[u] = 1;
	for(auto x: g[u]){
		if(x == p) continue;
		dfs1(x, u);
		heightSum[u] += heightSum[x] + child[x]; // subtree height sum
		child[u] += child[x]; // subtree children number
	}
}

void dfs2(int u, int p){
	for(auto x: g[u]){
		if(x == p) continue;
		// for the parent node, calculate sum of distance excluding x child
		distSum[x] = distSum[u] - (heightSum[x] + child[x]); 
		// then add how much the x subtree's contribution
		distSum[x] +=  heightSum[x] + (child[1] - child[x]);
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

	distSum[1] = heightSum[1];

	dfs2(1, 0);

	for(int i = 1; i <= n; i++){
		 // cout << heightSum[i] << " " << distSum[i] << "\n"; 
		 cout << distSum[i] << " ";
	}

}