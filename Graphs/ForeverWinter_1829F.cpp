#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> deg(n);
        vector<vector<int>> graph(n);
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            deg[u]++;
            deg[v]++;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int node = 0;
        vector<int> vis(n);
        queue<pair<int, int>> bfs;

        for (int i = 0; i < n; ++i)
        {
            // cout<<i<<" "<<deg[i]<<" \n";
            if (deg[i] == 1)
            {
                bfs.push({i, 0});
                vis[i]++;
            }
        }
        // cout<<"\n";
        int xx = 0, y = 0;

        while (!bfs.empty())
        {
            pair<int, int> temp = bfs.front();
            bfs.pop();
            int cur_node = temp.first;
            int dep = temp.second;
            // cout<<cur_node<<" "<<dep<<" "<<deg[cur_node]<<"\n";
            if (dep == 1)
            {
                y = deg[cur_node];
                y--;
            }

            if (dep == 2)
            {
                xx = deg[cur_node];
            }

            if (dep == 2)
                break;

            for (auto &x : graph[cur_node])
            {
                if (vis[x])
                    continue;

                bfs.push({x, dep + 1});
                vis[x]++;
            }
        }

        cout << xx << " " << y << "\n";
    }
}