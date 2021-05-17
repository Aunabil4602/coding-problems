#include <bits/stdc++.h>
#define LL long long

const LL N = 1000005;
const LL MOD = 1000000009L;

using namespace std;

LL n;
LL A;
LL S;
LL d[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> A;

    S = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        S += d[i];
    }

    for (int i = 0; i < n; i++)
    {
        LL low = max(1LL, A - (S - d[i]));
        LL high = min(d[i], A - (n - 1));

        cout << (d[i] - (high - low + 1)) << " ";
    }
}
