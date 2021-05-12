#include <bits/stdc++.h>
#define LL long long
#define N 100005
#define MOD 1000000007

using namespace std;

int n, m;
int Q[N];
int A[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> Q[i];
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    sort(Q, Q + m);
    sort(A, A + n);

    LL total = 0;
    for (int i = 0; i < n; i++)
    {
        total += A[i];
    }

    LL sum = 0;
    for (int i = n - 1; i >= 0; i -= Q[0])
    {
        for (int j = i, k = 0; k < 2 && (j - Q[0]) >= 0; j--, k++, i--)
        {
            sum += A[j - Q[0]];
        }
    }

    cout << total - sum << endl;
}
