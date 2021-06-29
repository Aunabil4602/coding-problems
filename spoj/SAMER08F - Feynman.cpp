#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 105;

int dp[N][N];
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof dp);
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            dp[i][j] = min(i, j) + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    while (cin >> n && n > 0)
    {
        cout << dp[n][n] << "\n";
    }

    return 0;
}
