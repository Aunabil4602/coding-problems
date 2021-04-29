#include <bits/stdc++.h>
#define LL long long

using namespace std;

int arr[100005];

int main()
{
    int n, k;
    cin >> n >> k;

    map<int, int> dp;
    int x;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        x = arr[i] ;
        if (x%k==0 && dp[x / k] == 0)
        {
            dp[x] = 1;
            cnt++;
        }else if (x%k!=0){
            dp[x] = 1;
            cnt++;
        }
    }

    cout << cnt << endl;
}
