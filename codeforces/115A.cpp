#include <bits/stdc++.h>

using namespace std;

int parent[2005];
int depth[2005];
int n;
int Max = -1;

void dfs(int v)
{
    if (v == -1)
        return;
    if (depth[v] != -1)
        return;

    dfs(parent[v]);
    if (parent[v] == -1)
    {
        depth[v] = 1;
    }
    else
    {
        depth[v] = 1 + depth[parent[v]];
    }
    Max = max(depth[v], Max);
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> parent[i + 1];
    }

    for (int i = 0; i < n; i++)
        depth[i + 1] = -1;

    for (int i = 0; i < n; i++)
    {
        if (depth[i + 1] == -1)
            dfs(i + 1);
    }
    cout << Max << endl;
}
