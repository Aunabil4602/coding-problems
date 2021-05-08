#include <bits/stdc++.h>
#define LL long long
#define N 200005
#define MOD 1000000007

using namespace std;

LL n, k;
map<LL, LL> cnt1, cnt2;
LL arr[N];

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    LL answer = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        answer += cnt2[arr[i] * k];

        cnt2[arr[i]] += cnt1[arr[i] * k];
        cnt1[arr[i]]++;
    }
    cout << answer << endl;
}
