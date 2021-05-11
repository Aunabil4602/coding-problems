#include <bits/stdc++.h>
#define LL long long
#define N 100005
#define MOD 1000000007

using namespace std;

LL a, b;
int n;
map<int, int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    for (int i = 0; i < N; i++)
        dp[i] = 0;

    for (int i = 1; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            dp[i]++;
            if (i != a / i)
                dp[a / i]++;
        }
    }

    for (int i = 1; i <= sqrt(b); i++)
    {
        if (b % i == 0)
        {
            dp[i]++;
            if (i != b / i)
                dp[b / i]++;
        }
    }

    set<int> divs;
    for (auto p : dp)
    {
        if (p.second > 1)
        {
            divs.insert(p.first);
        }
    }

    cin >> n;
    while (n--)
    {
        cin >> a >> b;

        auto it = divs.upper_bound(b);
        if (it != divs.begin())
        {
            it--;
        }
        else
        {
            cout << -1 << endl;
            continue;
        }

        if (*it >= a)
        {
            cout << *it << endl;
        }
        else
            cout << -1 << endl;
    }
}
