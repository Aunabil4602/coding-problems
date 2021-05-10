#include <bits/stdc++.h>
#define LL long long
#define N 1000005
#define MOD 1000000007

using namespace std;

LL x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x;

    if(x<=2){
        cout<<-1<<endl;
        return 0;
    }

    bool isOdd = x & 1;
    if (!isOdd)
        x /= 2;

    if (!(x & 1))
    {
        LL times = x / 2;
        cout << 3 * times << " " << 5 * times << endl;
        return 0;
    }

    LL y = (x * x - 1) / 2;
    LL z = y + 1;

    if (!isOdd)
        y *= 2;
    if (!isOdd)
        z *= 2;

    cout << y << " " << z << endl;
}
