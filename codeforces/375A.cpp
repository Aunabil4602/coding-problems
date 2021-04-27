#include <bits/stdc++.h>

using namespace std;

int arr[] = {1, 6, 8, 9};

int main()
{
    string num;
    cin >> num;

    map<int, int> dp;
    dp[1] = 1;
    dp[6] = 1;
    dp[8] = 1;
    dp[9] = 1;

    int cnt = 0;
    string answer;

    int rem = 0;
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == '0')
            cnt++;
        else
        {
            if (dp[num[i] - '0'])
            {
                dp[num[i] - '0'] = 0;
            }
            else
                answer += num[i];
        }
    }

    for (int i = 0; i < answer.length(); i++)
    {
        rem = (rem * 10 + (answer[i] - '0')) % 7;
    }

    do
    {
        int drem = rem;
        for (int i = 0; i < 4; i++)
        {
            drem = (drem * 10 + arr[i]) % 7;
        }

        if (drem == 0)
        {

            for (int i = 0; i < 4; i++)
            {
                answer += ('0' + arr[i]);
            }

            for (int i = 0; i < cnt; i++)
                answer += '0';
            cout << answer << endl;
            break;
        }

    } while (next_permutation(arr, arr + 4));
}
