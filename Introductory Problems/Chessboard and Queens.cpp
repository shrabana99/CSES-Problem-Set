#include <bits/stdc++.h>
 
using namespace std;

char board[8][8];
int rows[8], cols[8], diag1[20], diag2[20];
int cnt = 0;

void check(int row){
	if(row == 8){
		cnt++;
		return;
	}

	for(int col = 0; col < 8; col++){
		if(board[row][col] == '.' && rows[row] == 0 && cols[col] == 0 && diag1[row + col] == 0 && diag2[8 + row - col] == 0){
			rows[row] = cols[col] = diag1[row+col] = diag2[8+row-col] = 1;
			check(row + 1);
			rows[row] = cols[col] = diag1[row+col] = diag2[8+row-col] = 0;
		}
	}
}

int main(){
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			cin >> board[i][j];

	check(0);
	cout << cnt;
}