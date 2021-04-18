#include <bits/stdc++.h>

using namespace std;

const int maxN=2e5+5;
vector<int> g[maxN];

int fur, maxDepth = INT_MIN; // furtest point -> fur

void dfs(int u, int p, int depth){
	if(depth > maxDepth){
		maxDepth = depth;
		fur = u;
	}
	for(auto x: g[u]){
		if(x == p) continue;
		dfs(x, u, depth+1);
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

	dfs(1, 0, 0); 

	maxDepth = INT_MIN;
	dfs(fur, 0, 0);

	cout << maxDepth << endl;
}