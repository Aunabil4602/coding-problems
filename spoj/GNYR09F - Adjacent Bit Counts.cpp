#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 105;
const LL MOD = 1000000007;

LL dp[N][2][N];
int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof dp);
    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][0][j] = dp[i - 1][0][j] + dp[i - 1][1][j];
            dp[i][1][j] = dp[i - 1][0][j];
            if (j > 0)
                dp[i][1][j] += dp[i - 1][1][j - 1];
        }
    }

    int P, cases;
    cin >> P;
    while (P--)
    {
        cin >> cases >> n >> k;
        cout << cases << " " << (dp[n][0][k] + dp[n][1][k]) << endl;
    }

    return 0;
}
