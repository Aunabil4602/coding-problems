#include <bits/stdc++.h>
#define LL long long
#define N 1000005
#define MOD 1000000007

using namespace std;

int n;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int cnt = 0;

    for (int i = 0; i < 15; i++)
    {
        cout << arr[i] << endl;
        cin >> s;
        fflush(stdout);

        if (s == "yes")
            cnt++;
        if (cnt > 1)
        {
            cout << "composite" << endl;
            return 0;
        }
    }

    int sq[] = {4, 9, 25, 49};
    for (int i = 0; i < 4; i++)
    {
        cout << sq[i] << endl;
        cin >> s;
        fflush(stdout);

        if (s == "yes")
        {
            cout << "composite" << endl;
            return 0;
        }
    }

    cout << "prime" << endl;
}
