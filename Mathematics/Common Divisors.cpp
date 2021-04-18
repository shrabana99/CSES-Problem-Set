#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;


int main(){
	ll n;
	cin >> n;
	ll lim = 1e6+5;
	ll cnt[lim];
	memset(cnt, 0, sizeof(cnt));
	for(ll i = 0; i < n; i++){
		ll x; 
		cin >> x;
		cnt[x]++;
	}

	for(ll i = lim-1; i > 0; i--){
		ll c = 0;
		for(ll j = i; j < lim; j+= i)
			c += cnt[j];
		if(c >= 2){
			cout << i;
			return 0;
		}
	}

}