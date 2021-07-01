#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 100005;
const LL MOD = 1000000007;

LL dp[N];
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    string s;
    while (n--)
    {
        cin >> s;
        memset(dp, 0, sizeof dp);
        LL nxt, old = 1;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            nxt = old;
            nxt += (old - dp[c - 'A'] + MOD) % MOD;
            nxt = (nxt + MOD)%MOD;
            dp[c - 'A'] = old;
            old = nxt;
        }

        cout << nxt << endl;
    }

    return 0;
}
