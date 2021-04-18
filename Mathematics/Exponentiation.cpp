#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
 
const ll MOD = 1e9+7;

ll power(ll a, ll b){
    if(b == 0)
        return 1;

    ll res = power(a, b/2);
    res = (res*res)%MOD;

    if(b%2 == 1)
        res = (res*a)%MOD;
    return res;
}

int main(){
    ll n;
    cin >> n;
    while(n--){
        ll a, b;
        cin >> a >> b;
        cout << power(a, b) << " "; 
    }
}