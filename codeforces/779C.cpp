#include <bits/stdc++.h>
#define LL long long

using namespace std;

int a[200005];
int b[200005];
int n, k;

int main()
{
    int sum = 0;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sum += b[i];
        b[i] = a[i] - b[i];
    }

    sort(b, b + n);
    for (int i = 0; i < k || (i < n && b[i] < 0); i++)
    {
        sum += b[i];
    }

    cout << sum << endl;
}
