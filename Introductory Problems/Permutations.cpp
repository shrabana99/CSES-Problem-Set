#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    if(n == 1)
        cout << "1";
    else if(n == 4)
        cout << "3 1 4 2";
    else if(n < 5)
        cout << "NO SOLUTION";
    else{
        for(int i = 1; i <= n/2; i++){
            cout << i << " " << i+(n+1)/2 << " ";
        }
        if(n%2)
            cout << n/2 + 1;
    }
}
 
//1 4 2 5 3