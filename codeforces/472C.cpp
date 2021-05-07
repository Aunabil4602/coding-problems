#include <bits/stdc++.h>
#define LL long long
#define N 100005
#define MOD 1000000007

using namespace std;

int n;
string s[N][2];
int p[N];
pair<string, int> handles[N * 2];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i][0] >> s[i][1];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++)
    {
        handles[i * 2] = make_pair(s[i][0], i + 1);
        handles[i * 2 + 1] = make_pair(s[i][1], i + 1);
    }

    sort(handles, handles + n * 2);

    int i = 0, j = 0;
    while (i < 2 * n && j < n)
    {
        if (handles[i].second == p[j])
        {
            j++;
        }
        i++;
    }

    if (j == n)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}
