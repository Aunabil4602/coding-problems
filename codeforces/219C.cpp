#include <bits/stdc++.h>
#define LL long long
#define N 500005
#define MOD 1000000007
#define VECI vector<long long>

using namespace std;

int n, k;
string s;
int dp[N][26];
int parent[N][26];
int minLeftColor[28], minRightColor[28];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        int curColor = (s[i] - 'A');
        int prevColor = (s[i - 1] - 'A');

        for (int j = 0; j < k; j++)
        {
            int parentColor = 0;
            if (j > 0 && j < k - 1)
            {
                if (i > 0)
                {
                    if (dp[i - 1][minLeftColor[j - 1]] < dp[i - 1][minRightColor[j + 1]])
                        parentColor = minLeftColor[j - 1];
                    else
                        parentColor = minRightColor[j + 1];
                }
            }
            else if (j > 0)
            {
                parentColor = minLeftColor[j - 1];
            }
            else
            {
                parentColor = minRightColor[j + 1];
            }

            dp[i][j] = (j != curColor);
            if (i > 0)
            {
                dp[i][j] += dp[i - 1][parentColor];
                parent[i][j] = parentColor;
            }
        }

        int minValue = 1e7;
        for (int j = 0; j < k; j++)
        {
            if (dp[i][j] < minValue)
            {
                minLeftColor[j] = j;
                minValue = dp[i][j];
            }
            else
            {
                minLeftColor[j] = minLeftColor[j - 1];
            }
        }

        minValue = 1e7;
        for (int j = k - 1; j >= 0; j--)
        {
            if (dp[i][j] < minValue)
            {
                minRightColor[j] = j;
                minValue = dp[i][j];
            }
            else
            {
                minRightColor[j] = minRightColor[j + 1];
            }
        }
    }

    int minColor = 0;
    int minValue = 1e7;

    for (int i = 0; i < k; i++)
    {
        if (minValue > dp[n - 1][i])
        {
            minValue = dp[n - 1][i];
            minColor = i;
        }
    }

    string minString;
    minString += char('A' + minColor);
    for (int i = n - 1; i > 0; i--)
    {
        minString += char('A' + parent[i][minColor]);
        minColor = parent[i][minColor];
    }

    reverse(minString.begin(), minString.end());

    cout << minValue << endl;
    cout << minString << endl;
}
