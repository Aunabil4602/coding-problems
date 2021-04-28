#include <bits/stdc++.h>
#define LL long long

using namespace std;

vector<int> adj[100005];
int n, m;
int color[100005];
int visit[100005];

bool doBfs(int node)
{
    queue<int> bfs;
    bfs.push(node);
    visit[node] = 1;
    color[node] = 1;
    bool ans = true;

    while (!bfs.empty())
    {
        int current = bfs.front();
        bfs.pop();

        for (int node : adj[current])
        {
            if (visit[node] == 0)
            {
                color[node] = !color[current];
                visit[node] = 1;
                bfs.push(node);
            }
            else if (color[node] == color[current])
            {
                ans = false;
                break;
            }
        }

        if (ans == false)
        {
            break;
        }
    }

    return ans;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        visit[i] = 0;
    }

    bool ans = true;
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 0)
        {
            ans = doBfs(i);
            if (ans == false)
            {
                break;
            }
        }
    }

    if (ans == false)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> a[2];
        for (int i = 1; i <= n; i++)
        {
            a[color[i]].push_back(i);
        }

        cout << a[0].size() << endl;
        for (int i = 0; i < a[0].size(); i++)
            cout << a[0][i] << " ";
        cout << endl;

        cout << a[1].size() << endl;
        for (int i = 0; i < a[1].size(); i++)
            cout << a[1][i] << " ";
        cout << endl;
    }
}
