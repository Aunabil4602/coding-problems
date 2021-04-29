#include <bits/stdc++.h>
#define LL long long

using namespace std;

map<int, int> dp;
int n;
int m;

int main()
{
    cin >> n >> m;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        dp[x] = 1;
    }

    vector<int> toBuy;
    for (int i = 1; i <= m; i++)
    {
        if (dp[i])
            continue;

        m -= i;
        toBuy.push_back(i);
    }

    cout << toBuy.size() << endl;
    for (auto x : toBuy)
    {
        cout << x << " ";
    }
    cout << endl;
}
