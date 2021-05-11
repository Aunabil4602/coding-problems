#include <bits/stdc++.h>
#define LL long long
#define N 1000005
#define MOD 1000000007

using namespace std;

int n, h, d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d >> h;

    if (d > 2 * h || (d==1 && n>2))
    {
        cout << -1 << endl;
        return 0;
    }

    int sides = 0;
    for (int i = 1; i <= h; i++, sides++)
    {
        cout << i << " " << i + 1 << endl;
    }

    for (int i = h + 2, j = 0; j < d - h; i++, sides++, j++)
    {
        int last = i - 1;
        if (i == h + 2)
            last = 1;

        cout << last << " " << i << endl;
    }

    int last = 1;
    if (h == d)
        last = 2;
    while (sides != n - 1)
    {
        cout << last << " " << sides + 2 << endl;
        sides++;
    }
}
