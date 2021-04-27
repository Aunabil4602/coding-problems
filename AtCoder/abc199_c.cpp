#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, Q;
    string s, S[2];

    cin >> N;
    cin >> s;
    cin >> Q;

    S[0] = s.substr(0, N);
    S[1] = s.substr(N, N);

    int start = 0;

    int T, A, B;
    for (int i = 0; i < Q; i++)
    {
        cin >> T >> A >> B;
        if (T == 2)
        {
            start = !start;
        }
        else
        {
            if (B <= N)
            {
                swap(S[start][A - 1], S[start][B - 1]);
            }
            else if (A > N)
            {
                swap(S[!start][(A - 1)%N], S[!start][(B - 1)%N]);
            }
            else
            {
                swap(S[start][A - 1], S[!start][(B - 1) % N]);
            }
        }
    }
    cout << S[start] << S[!start] << endl;
}
