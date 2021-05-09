#include <bits/stdc++.h>
#define LL long long
#define N 1000005
#define MOD 1000000007

using namespace std;

int n;
int arr[N];
int dp[N];
int cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr[a] = b;
    }

    cnt[0] = (arr[0] > 0);
    for (int i = 1; i < N; i++)
    {
        cnt[i] = arr[i] > 0;
        cnt[i] += cnt[i - 1];
    }

    dp[0] = 0;
    int answer = cnt[N - 1] - cnt[0];
    for (int i = 1; i < N; i++)
    {
        int lastDp = 0;
        int lastCnt = 0;
        if (i - arr[i] - 1 >= 0)
        {
            lastDp = dp[i - arr[i] - 1];
            lastCnt = cnt[i - arr[i] - 1];
        }

        dp[i] = lastDp + cnt[i - 1] - lastCnt;
        answer = min(answer, dp[i] + cnt[N - 1] - cnt[i]);
    }

    cout << answer << endl;
}
