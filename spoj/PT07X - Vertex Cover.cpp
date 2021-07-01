#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 100005;

int dp1[N], dp2[N];
vector<int> adj[N];
int n;

void solve(int x, int p)
{
    dp1[x] = 1;
    dp2[x] = 0;
    for (int &v : adj[x])
    {
        if (v == p)
            continue;

        solve(v, x);
        dp2[x] += dp1[v];
        dp1[x] += min(dp1[v], dp2[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solve(1, -1);
    cout << min(dp1[1], dp2[1]);

    return 0;
}
