#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    multiset<int, greater<int>> st;
    while (n--) { int x; cin >> x; st.insert(x); }
    while (m--)
    {
        int x; cin >> x;
        auto it = st.lower_bound(x);
        if (it == st.end()) cout << "-1\n";
        else { cout << *it << '\n'; st.erase(it); }
    }
}

