#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> a;

    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        a.push_back({x, 0});
        a.push_back({y, 1});
    }

    sort(a.begin(), a.end());

    int ans = 0, cnt = 0;
    for(auto x: a){
        if(x.second == 0)
            cnt++;
        else
            cnt--;

        ans = max(ans, cnt);
    }
    cout << ans;
}

