#include <bits/stdc++.h>
 
using namespace std;
 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    string s;
    cin >> n >> m;
 
    char a[n][m], prev[n][m];
    bool vis[n][m];
    memset(vis, false, sizeof(vis));
    queue< pair<int, int> > q;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            prev[i][j] = '.';
            if(a[i][j] == 'A')  {
                q.push({i, j});
                vis[i][j] = true;
                prev[i][j] = '#';
            }
        }
    }
 
    while(!q.empty()){
        int x = q.front().first; 
        int y = q.front().second; 
        q.pop();
 
        if(a[x][y] == 'B') {
            while(prev[x][y] != '#'){
                char c = prev[x][y];
                s += c; 
                if(c == 'U') x++;
                else if(c == 'D') x--;
                else if(c == 'L') y++;
                else y--;
            }
 
            reverse(s.begin(), s.end());
            cout << "YES\n" << s.size() << " " << s; 
            return 0;
        }
 
        //a[x][y] = '#';
 
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] != '#'){
                q.push({nx, ny});
                vis[nx][ny] = true;
                prev[nx][ny] = dir[i];
            }
        }
    }
    cout << "NO";
}