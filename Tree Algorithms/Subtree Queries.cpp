#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxN=2e5+5;
vector<ll> g[maxN];

ll tin[maxN], tout[maxN], val[maxN], BIT[maxN]; 
ll timer = 0;

void update(ll pos, ll v){
	while(pos < maxN){
		BIT[pos] += v;
		pos += (pos & -pos); 
	}
}

ll query(ll pos){
	ll sum = 0;
	while(pos > 0){
		sum += BIT[pos];
		pos -= (pos & -pos);
	}
	return sum; 
}

void dfs(ll u, ll p){
	tin[u] = ++timer;

	for(auto x: g[u]){
		if(x != p) dfs(x, u);
	}
	tout[u] = timer;
}

int main(){
	ll n, q;
	cin >> n >> q;

	for(ll i = 1; i <= n; i++) cin >> val[i];

	for(ll i = 0, x, y; i < n-1; i++){
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, 0);
	for(ll i = 1; i <= n; i++) update(tin[i], val[i]);

	while(q--){
		ll qtype; 
		cin >> qtype;
		if(qtype == 1){
			ll u, x;
			cin >> u >> x;
			update(tin[u], x - val[u]);
			val[u] = x;
		}
		else{
			ll u;
			cin >> u; // cout << u << " ";
			cout << query(tout[u]) - query(tin[u] - 1) << endl;
		}
		
	} 
}