#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    map<string, int> dp;
    string s;

    cin >> n;
    while (n--)
    {
        cin >> s;
        dp[s]++;
        if (dp[s] == 1)
        {
            cout << "OK" << endl;
        }
        else
        {
            int count = dp[s] - 1;
            cout << s << to_string(count) << endl;
        }
    }
}
