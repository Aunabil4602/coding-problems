#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 105;
const LL MOD = 1000000007;

LL dp[11][100][2];
int digit[11];
int n, k;

LL solve(int idx, int sum, int tight)
{
    if (idx == 0)
        return sum;
    if (dp[idx][sum][tight] != -1)
        return dp[idx][sum][tight];

    LL res = 0;
    for (int i = 0; i < 10; i++)
    {
        int t = (i == digit[idx - 1]) ? tight : 0;
        if (tight && i > digit[idx - 1])
            break;

        res += solve(idx - 1, sum + i, t);
    }

    return dp[idx][sum][tight] = res;
}

int findDigits(int x)
{
    int cnt = 0;
    memset(digit, 0, sizeof digit);
    while (x > 0)
    {
        digit[cnt++] = x % 10;
        x /= 10;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    while (cin >> a >> b && a != -1 && b != -1)
    {
        memset(dp, -1, sizeof dp);
        int szb = findDigits(b);
        LL bb = solve(szb, 0, 1);

        // cout << bb << endl;

        memset(dp, -1, sizeof dp);
        int sza = findDigits(a - 1);
        LL aa = solve(sza, 0, 1);

        cout << (bb - aa) << endl;
    }

    return 0;
}
