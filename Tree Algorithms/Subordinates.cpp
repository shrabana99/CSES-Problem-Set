#include <bits/stdc++.h>
 
using namespace std;

void dfs(int u, vector<vector<int>> &g, vector<int> &child){
	child[u]++;
	for(auto x: g[u]){ 
		dfs(x, g, child);
		child[u] += child[x];
	} 
}

int main(){
	int n;
	cin >> n;

	vector<vector<int>> g(n+1);
	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		g[x].push_back(i);
	}

	vector<int> child(n+1, 0);
	dfs(1, g, child);
	for(int i = 1; i <= n; i++){
		cout << child[i]-1 << " ";
	}
}