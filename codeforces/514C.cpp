#include <bits/stdc++.h> // rolling hash
#define LL long long

const LL N = 1000005;
const LL MOD = 1000000000000000003L;
const LL P = 3;

using namespace std;

string s;
int n, m;
set<LL> dp[N];
LL powerP[N];

void createHash(string s)
{
    int length = s.length();
    LL rollHash = 0;
    LL curP = 1;

    for (char c : s)
    {
        int value = c - 'a'+1;
        rollHash += (value * curP) % MOD;
        rollHash %= MOD;

        curP *= P;
        curP %= MOD;
    }

    dp[length].insert(rollHash);
}

bool query(string s)
{
    int length = s.length();
    LL rollHash = 0;
    LL curP = 1;

    for (char c : s)
    {
        int value = c - 'a' +1;
        rollHash += (value * curP) % MOD;
        rollHash %= MOD;

        curP *= P;
        curP %= MOD;
    }

    for (int i = 0; i < length; i++)
    {
        int c = s[i] - 'a'+1;
        for (int j = 1; j <= 3; j++)
        {
            if (c == j)
            {
                continue;
            }

            LL toSub = (c * powerP[i]) % MOD;
            LL toAdd = (j * powerP[i]) % MOD;

            LL newHash = ((rollHash - toSub + MOD) % MOD + toAdd) % MOD;
            if (dp[length].find(newHash) != dp[length].end())
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    powerP[0] = 1;
    for (int i = 1; i < N; i++)
    {
        powerP[i] = powerP[i - 1] * P;
        powerP[i] %= MOD;
    }

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        createHash(s);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (query(s))
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}
