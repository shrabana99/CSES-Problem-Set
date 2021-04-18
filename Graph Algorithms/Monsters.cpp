#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
 
    char board[n][m], direction[n][m];
    int vis[n][m];
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    char dir[] = {'D', 'U', 'R', 'L'};
    memset(vis, 0, sizeof(vis));

    queue< pair< pair<int, int>, bool > > q;
    int sx, sy;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'A')
                sx = i, sy = j;
            if(board[i][j] == 'M') 
                q.push({ {i, j}, false }), vis[i][j] = 2; // monster
        }
    }

    // taking monsters before in the queue to ensure
    // to cover worst case
    q.push({ {sx, sy}, true }), vis[sx][sy] = 1, direction[sx][sy] = 's'; // human 

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        bool flag = q.front().second; // is human or not
        q.pop();

        if(x == 0 || y == 0 || x == n-1 || y == m-1){ // reached the end
            if(flag){ // human
                string s;
                while(direction[x][y] != 's'){
                    char c = direction[x][y];
                    s += c;
                    if(c == 'U') x++;
                    else if(c == 'D') x--;
                    else if(c == 'R') y--;
                    else y++;
                }
                reverse(s.begin(), s.end());
                cout << "YES\n" << s.size() << endl << s;
                return 0;
            }
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] != '#'){
                if(flag && !vis[nx][ny]) {
                    q.push( { {nx, ny}, flag } );
                    vis[nx][ny] = 1;
                    direction[nx][ny] = dir[i];
                }
                else if(!flag && vis[nx][ny] != 2){
                    q.push( { {nx, ny}, flag } );
                    vis[nx][ny] = 2;
                }
            }
        }
    }
    
    cout << "NO";
}