#include <bits/stdc++.h>
#define LL long long
#define N 1000005
#define MOD 1000000007

using namespace std;

int n;
int arr[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[x]++;
    }

    int answer = 0;
    int max = 1000000;
    for (int i = 0; i < max; i++)
    {
        answer += arr[i] & 1;

        arr[i + 1] += arr[i]>>1;
    }

    for (int i = 0; i < 30; i++)
    {
        answer += (arr[max] >> i) & 1;
    }

    cout << answer << endl;
}
