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
    return power(x, MOD-2);
}
void pre(){
    f[0] = 1;
    for(ll i = 1; i < lim; i++){
        f[i] = (f[i-1] * i) % MOD; 
    }
}

ll nCr(ll n, ll r){ 
    return ( (inv(f[r])*inv(f[n-r]))%MOD * f[n]) % MOD;
}

int main(){  
    pre();

    ll n;
    cin >> n;
    while(n--){
        ll n, r;
        cin >> n >> r;
        cout << nCr(n, r) << " ";
    }
}