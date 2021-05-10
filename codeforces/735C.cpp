#include <bits/stdc++.h>
#define LL long long
#define N 1000005
#define MOD 1000000007

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LL n;
    LL dp[1000];

    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 3;

    cin >> n;

    LL answer;
    if (n == 2)
    {
        answer = 1;
    }
    else if (n == 3)
    {
        answer = 2;
    }
    else
    {   
        answer = 2;
        for (int i = 3; i < 1000; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
            if (dp[i] <= n)
            {
                answer = i;
            }
            else
                break;
        }
    }

    cout << answer << endl;
}
