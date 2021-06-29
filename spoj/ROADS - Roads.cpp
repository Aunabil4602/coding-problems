#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 105;

int dp[N][N * N];
vector<int> adj[N], toll[N], len[N];
int n, K, R, s, d, l, t;

int solveDp(int node, int cost)
{
    if (dp[node][cost] != -1)
        return dp[node][cost];
    if (node == 1)
    {
        if (cost == 0)
            return 0;
        else
            return 100000;
    }
    dp[node][cost] = 100000;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (cost>=toll[node][i] && solveDp(adj[node][i], cost - toll[node][i]) < 100000)
        {
            dp[node][cost] = min(dp[node][cost],
                                 solveDp(adj[node][i], cost - toll[node][i]) + len[node][i]);
        }
    }

    return dp[node][cost];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while (cases--)
    {
        for (int i = 0; i < N; i++)
        {
            adj[i].clear();
            toll[i].clear();
            len[i].clear();
        }

        cin >> K >> n >> R;

        for (int i = 0; i < R; i++)
        {
            cin >> s >> d >> l >> t;
            adj[d].push_back(s);
            toll[d].push_back(t);
            len[d].push_back(l);
        }

        memset(dp, -1, sizeof dp);
        int answer = 100000;
        for (int i = K; i >= 0; i--)
        {
            if (solveDp(n, i) < 100000)
            {
                answer = min(answer, dp[n][i]);
            }
        }

        if (answer != 100000)
            cout << answer << "\n";
        else
            cout << "-1"
                 << "\n";
        cout << endl;
    }

    return 0;
}
