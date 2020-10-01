#include <bits/stdc++.h>
 
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string a;
	cin >> a;

	int n = a.size();
	int z[n];
	memset(z, 0, sizeof(z));

	int left = 0, right = 0;
    for(int i = 1; i < n; i++){// z[0] is always zero
        if(i <= right){ // i is inside the window (l ,r)
            // find its equivalent postion (i - left) and use it
        	z[i] = min(right - i + 1, z[i - left]);
        }
        
   		// extend the current suffix s(0, i)
   		while(i + z[i] < n && a[z[i]] == a[i + z[i]])
   			z[i]++;

   		// update new window
   		if(i + z[i] - 1 > right)
   			left = i, right = i + z[i] - 1;
    }

	for(int i = n-1; i > 0; i--){
		if(i+z[i] == n)
			printf("%d ", z[i]);
	}

}