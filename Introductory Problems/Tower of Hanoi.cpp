#include <bits/stdc++.h>
using namespace std;

void TOH(int n, int source, int temp, int dest){
	if(n == 1){
		cout << source << " " << dest << endl;
		return; 
	}
	TOH(n-1, source, dest, temp);
	cout << source << " " << dest << endl;
	TOH(n-1, temp, source, dest);
}

int main(){

	int n;
	cin >> n;

	cout << (1 << n)-1 << endl;
	TOH(n, 1, 2, 3);

}