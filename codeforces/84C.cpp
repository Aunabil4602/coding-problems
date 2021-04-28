#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int result7 = n / 7;
    for (int i = result7; i >= 0; i--)
    {
        int result4 = (n - (i * 7)) / 4;
        if (i * 7 + result4 * 4 == n)
        {
            for (int j = 0; j < result4; j++)
                cout << 4;
            for (int j = 0; j < i; j++)
                cout << 7;
            return 0;
        }
    }
    cout << -1 << endl;
}
