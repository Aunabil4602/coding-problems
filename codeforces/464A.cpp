#include <bits/stdc++.h>
#define LL long long
#define N 100005
#define MOD 1000000007
#define PP pair<int, int>

using namespace std;

string s;
int n, p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p;
    cin >> s;

    if (p == 1)
    {
        cout << "NO"
             << "\n";
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            int curChar = s[i] - 'a';
            int next = -1;

            for (int j = curChar + 1; j < p; j++)
            {
                if (i > 0 && (s[i - 1] - 'a') == j)
                {
                    continue;
                }

                if (i > 1 && (s[i - 2] - 'a') == j)
                {
                    continue;
                }
                next = j;
                break;
            }

            if (next != -1)
            {
                string answer = s.substr(0, i);
                answer += ('a' + next);
                for (int j = i + 1; j < n; j++)
                {
                    for (int k = 0; k < p; k++)
                    {
                        if (answer.back() == ('a' + k))
                        {
                            continue;
                        }
                        if (answer.length() > 1 && (answer[(int)answer.length() - 2] - 'a') == k)
                        {
                            continue;
                        }
                        answer += (k + 'a');
                        break;
                    }
                }

                cout << answer << "\n";
                return 0;
            }
        }

        cout << "NO"
             << "\n";
    }
}
