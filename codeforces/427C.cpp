#include <bits/stdc++.h> // kosaraju's algorithm for finding SCC
#define LL long long
#define N 100005
#define MOD 1000000007

using namespace std;

int n, m;
vector<int> adj[N], rev_adj[N];
LL cost[N];
stack<int> st;
int visit[N];
LL min_value;
LL min_count;

void dfs1(int v)
{
    visit[v] = 1;
    for (int x : adj[v])
    {
        if (visit[x] == 0)
        {
            dfs1(x);
        }
    }
    st.push(v);
}

void dfs2(int v)
{
    visit[v] = 1;

    if (min_value > cost[v])
    {
        min_value = cost[v];
        min_count = 1;
    }
    else if (min_value == cost[v])
    {
        min_count++;
    }

    for (int x : rev_adj[v])
    {
        if (visit[x] == 0)
        {
            dfs2(x);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }

    cin >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        visit[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 0)
        {
            dfs1(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        visit[i] = 0;
    }

    LL answer_min = 0;
    LL answer_ways = 1;
    while (st.empty() == false)
    {
        int v = st.top();
        st.pop();

        if (visit[v] == 0)
        {
            min_value = 1e9 + 10;
            min_count = 0;
            dfs2(v);
            answer_min += min_value;

            answer_ways *= min_count;
            answer_ways %= MOD;
        }
    }

    cout << answer_min << " " << answer_ways << endl;
}
