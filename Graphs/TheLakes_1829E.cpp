// BFS traversal based question... Expected in coding interviews of faang companies

#include <bits/stdc++.h>

using namespace std;

void ak()
{
    int n, m;
    cin >> n >> m;

    long long grid[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<long long>> vis(n, vector<long long>(m));
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (vis[i][j] == 1)
                continue;
            if (grid[i][j] == 0)
                continue;

            queue<pair<int, int>> bfs;
            bfs.push({i, j});

            vis[i][j]++;
            long long tot = 0;
            while (!bfs.empty())
            {
                pair<int, int> temp = bfs.front();
                bfs.pop();
                int x = temp.first;
                int y = temp.second;

                tot += grid[x][y];

                // moving left right up and down all x,y neighbours
                if ((x - 1) >= 0)
                {
                    if (grid[x - 1][y] > 0)
                    {
                        if (vis[x - 1][y] == 0)
                        {
                            vis[x - 1][y]++;
                            bfs.push({x - 1, y});
                        }
                    }
                }

                //
                if ((x + 1) < n)
                {
                    if (grid[x + 1][y] > 0)
                    {
                        if (vis[x + 1][y] == 0)
                        {
                            vis[x + 1][y]++;
                            bfs.push({x + 1, y});
                        }
                    }
                }

                if ((y - 1) >= 0)
                {
                    if (grid[x][y - 1] > 0)
                    {
                        if (vis[x][y - 1] == 0)
                        {
                            vis[x][y - 1]++;
                            bfs.push({x, y - 1});
                        }
                    }
                }

                //
                if ((y + 1) < m)
                {
                    if (grid[x][y + 1] > 0)
                    {
                        if (vis[x][y + 1] == 0)
                        {
                            vis[x][y + 1]++;
                            bfs.push({x, y + 1});
                        }
                    }
                }
            }

            ans = max(ans, tot);
        }
    }

    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ak();
    }
    return 0;
}