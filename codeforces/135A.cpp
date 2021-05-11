#include <bits/stdc++.h>
#define LL long long
#define N 100005
#define MOD 1000000007

using namespace std;

int n;
int arr[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    if (arr[n - 1] != 1)
        arr[n - 1] = 1;
    else
        arr[n - 1] = 2;

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
