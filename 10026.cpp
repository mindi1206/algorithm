#include <cstdio>
#include <cstring>
#include <algorithm>
 
#define MAX 101
 
using namespace std;
 
bool is_visited[101][101];
char color[101][101] = { 0 };
char blind_color[101][101] = { 0 };
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
 
void dfs(char c, int x, int y, char(*arr)[MAX]) {
    is_visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int to_x = x + dx[i];
        int to_y = y + dy[i];
 
        if (arr[to_x][to_y] == c) {
            if (!is_visited[to_x][to_y]) {
                dfs(c, to_x, to_y, arr);
            }
        }
    }
}
 
int main() {
    int n;
 
    int res = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %c", &color[i][j]);
            blind_color[i][j] = color[i][j];
            if (blind_color[i][j] == 'G') blind_color[i][j] = 'R';
        }
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!is_visited[i][j]) {
                dfs(color[i][j], i, j, color);
                res++;
            }
        }
    }
    printf("%d ", res);
    res = 0;
    memset(is_visited, false, sizeof(is_visited));
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!is_visited[i][j]) {
                dfs(blind_color[i][j], i, j, blind_color);
                res++;
            }
        }
    }
    printf("%d\n", res);
}

