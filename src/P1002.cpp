#include <cstdio>
#include <iostream>
#include <string.h>
#define MAXN 100

using namespace std;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m, x, y;
int grid[MAXN][MAXN];
long long dp[MAXN][MAXN];

int main()
{
    cin >> n >> m >> x >> y;
    // 标记障碍点
    memset(grid, 0, sizeof(grid));
    memset(dp, 0, sizeof(dp));
    grid[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int cx = x + dx[i], cy = y + dy[i];
        if (cx >= 0 && cx <= n && cy >= 0 && cy <= m)
        {
            grid[cx][cy] = 1;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (!grid[i][0])
        {
            dp[i][0] = 1;
        }
        else
        {
            break;
        }
    }

    for (int j = 0; j <= m; j++)
    {
        if (!grid[0][j])
        {
            dp[0][j] = 1;
        }
        else
        {
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j])
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[n][m];
    return 0;
}