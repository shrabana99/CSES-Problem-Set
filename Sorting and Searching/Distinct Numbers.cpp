#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    set<int> s;
    int n;
    cin >> n;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        s.insert(x);
    }
    cout << s.size();

}

