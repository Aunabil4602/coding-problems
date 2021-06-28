#include <bits/stdc++.h> // O(nkn) or O(n^2.k)
#define LL long long

using namespace std;

const int N = 15;
const int K = 100;

int n, k, t;
int dp[N][K];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof dp);
    for (int i = 0; i < N; i++)
        dp[i][0] = 1;

    for (int i = 2; i < N; i++)
    {
        for (int j = 1; j < K; j++)
        {
            for (int m = max(0, j - i + 1); m < j; m++)
            {
                dp[i][j] += dp[i - 1][m];
            }
            dp[i][j] += dp[i - 1][j];
        }
    }

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }

    return 0;
}
