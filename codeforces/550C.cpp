#include <bits/stdc++.h>
#define LL long long

using namespace std;

int main()
{
    string s;
    cin >> s;

    int sum = 0;
    while (sum < 1000)
    {
        string num = to_string(sum);
        int i = 0, j = 0;

        while (i < num.length() && j < s.length())
        {
            if (num[i] == s[j])
            {
                i++;
            }
            j++;
        }

        if (i == num.length())
        {
            cout << "YES" << endl;
            cout << num << endl;
            return 0;
        }
        sum += 8;
    }

    cout << "NO" << endl;
}
