#include <bits/stdc++.h>
#define LL long long

const LL N = 1000005;
const LL MOD = 1000000009L;

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

    int mx = 0;
    int cnt = 0;
    int start;
    int ed;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
        {
            if (cnt == 0)
            {
                start = i;
            }
            ed = i;
            cnt++;
        }
        else
        {
            if (cnt > 0)
            {
                while (start <= ed)
                {
                    arr[start] = arr[start - 1];
                    start++;

                    arr[ed] = arr[ed + 1];
                    ed--;
                }
            }
            cnt = 0;
        }
        mx = max(cnt, mx);
    }

    if (cnt > 0)
    {
        while (start <= ed)
        {
            arr[start] = arr[start - 1];
            start++;

            arr[ed] = arr[ed + 1];
            ed--;
        }
    }

    cout << (mx + 1) / 2 << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
