#include <bits/stdc++.h>
#define LL long long
#define N 100005
#define MOD 1000000007

using namespace std;

int n;
int arr[N];
int dp[N];
int dp2[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        if (arr[i - 1] < arr[i])
        {
            dp[i] = dp[i - 1] + 1;
        }
    }

    dp2[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        dp2[i] = 1;
        if (arr[i] < arr[i + 1])
        {
            dp2[i] = dp2[i + 1] + 1;
        }
    }

    int answer = 1;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            answer = max(answer, dp[i - 1] + 1);
        }
        if (i < n - 2)
        {
            answer = max(answer, dp2[i + 1] + 1);
        }
        if (i > 0 && i < n - 1 && arr[i - 1] + 1 < arr[i + 1])
        {
            answer = max(answer, dp[i - 1] + 1 + dp2[i + 1]);
        }
    }

    cout << answer << endl;
}
