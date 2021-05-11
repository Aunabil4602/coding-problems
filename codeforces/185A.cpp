#include <bits/stdc++.h> //matrix exponentiation
#define LL long long
#define N 100005
#define MOD 1000000007
#define VECI vector<long long>

using namespace std;

LL n;
VECI base{3, 1, 1, 3};
VECI ones{1, 0, 0, 1};

VECI multiply(VECI a, VECI b)
{
    VECI x;
    x.push_back(((a[0] * b[0]) % MOD + (a[1] * b[2]) % MOD) % MOD);
    x.push_back(((a[0] * b[1]) % MOD + (a[1] * b[3]) % MOD) % MOD);
    x.push_back(((a[2] * b[0]) % MOD + (a[3] * b[2]) % MOD) % MOD);
    x.push_back(((a[2] * b[1]) % MOD + (a[3] * b[3]) % MOD) % MOD);

    return x;
}

VECI expo(LL n)
{
    if (n == 0)
        return ones;

    VECI mat = expo(n / 2);
    mat = multiply(mat, mat);
    if (n & 1)
        mat = multiply(mat, base);

    return mat;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    VECI result = expo(n);
    cout << result[0] << endl;
}
