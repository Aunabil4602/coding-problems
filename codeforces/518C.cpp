#include <bits/stdc++.h>
#define LL long long
#define N 100005
#define MOD 1000000007

using namespace std;

int n, k, m;
int order[N], pos[N];

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> order[i];
        order[i]--;
        pos[order[i]] = i;
    }

    LL answer = 0;
    int x;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        x--;
        answer += 1 + pos[x] / k;
        if (pos[x] > 0)
        {
            int y = order[pos[x] - 1];
            swap(order[pos[x]], order[pos[y]]);
            swap(pos[x], pos[y]);
        }
    }

    cout << answer << endl;
}
