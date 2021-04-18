#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
 
ll MOD = 1e9+7;
const ll lim = 1e6+5;
ll f[lim]; 

ll power(ll a, ll b){
    if(b == 0) return 1;
    ll r = power(a, b/2);
    r = (r*r)%MOD;
    if(b%2) 
        r = (r*a)%MOD;
    return r;
}

ll inv(ll x){
    if(x == 0)
        return 1;
    return power(x, MOD-2);
}
void pre(){
    f[0] = 1;
    for(ll i = 1; i < lim; i++){
        f[i] = (f[i-1] * i) % MOD; 
    }
}

int main(){  
    pre();

    vector<ll> fre(256);
    string s;
    cin >> s;

    for(auto x: s) fre[x]++;

    ll ans = f[s.size()]; 
    for(auto x: fre){ //cout << ans << " ";
        ans = (ans * inv(f[x])) % MOD;
    }
    cout << ans;
}