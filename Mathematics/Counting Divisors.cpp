#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
 
ll MOD = 1e9+7;
const ll lim = 1e6+5;
ll p[lim];


void pre(){
    for(ll i = 2; i < lim; i++) p[i] = i;

    for(ll i = 2; i < lim; i++){
        if(p[i] == i){ 
            for(ll j = i; j <= lim; j+=i){
                p[j] = min(p[j], i);
            } 
        }
    }
}

int main(){
    pre();

    ll n;
    cin >> n;
    while(n--){
        ll x;
        cin >> x;
        
        ll ans = 1;
        while(x != 1){
            ll cnt = 0, y = p[x];
            while(x%y == 0){
                x /= y;
                cnt++;
            }
            ans *= (cnt + 1);  
        }
        cout << ans << endl;
    }
}